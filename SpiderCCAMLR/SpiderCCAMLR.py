import re
import requests
from bs4 import BeautifulSoup
import pymysql
import time

def getHTMLText(url, kv):
        try:
                r = requests.get(url, params=kv)
                r.raise_for_status() # 收集状态码，如果不是200则抛出异常
                r.encoding = r.apparent_encoding # 保证编码一致
                return r.text
        except:
                return ""

def getNewsData(url, kv, db, succCount):
        html = getHTMLText(url, kv)
        soup = BeautifulSoup(html, "html.parser")

        # 查找新闻列表
        articlesoup = soup.find('article', {'id':'main-content'})
        pattern = re.compile(r'views-row.*')
        viewsoup = articlesoup.find('div', {'class':'view-content'})

        #遍历一个网页中的新闻
        for view in viewsoup.find_all('div', {'class':pattern}):
                try:
                        h2 = view.find('h2', {'class':'field-content'})# 先缩小范围
                        a = h2.find('a')
                        href = a.attrs['href'] # 找到新闻链接
                        title = a.string # 找到新闻标题
                        # 找到新闻时间
                        datetag = view.find_all('div', {'class':'news-body'})[-1]
                        date = datetag.string
                        #print(title + '\n' + href + '\n' + date,end='\n')
                        #succCount += 1
                        succCount = writeInDB(db, title, href, date, succCount)
                except:
                        continue
        return succCount

def getPageCount(url, kv):
        html = getHTMLText(url, kv)
        soup = BeautifulSoup(html, "html.parser")
        pagecount = soup.find_all('li', {'class':'pager-item'})
        return len(pagecount)+1


def writeInDB(db, title, href, date, succCount):
        cx = db.cursor()
        #SET SQL_SAFE_UPDATES = 0
        #delete from OceanNews
        #http://bbs.csdn.net/topics/70045444
        #title = title.replace("'","''")
        
        #href = href.replace("'","''")
        insertSql = 'insert into OceanNews (newsTitle, newsURL, newsDate) values("{0}", "{1}", "{2}");'.format(title, href, date)
        #insertSql = insertSql.encode('utf-8').decode('utf-8')
        #print(str(succCount) + '        ' + insertSql + '\n')
        cx.execute(insertSql)
        succCount += 1
        db.commit()
        cx.close()

        return succCount


def main():
        timestart = time.time()
        host = 'https://www.ccamlr.org'
        url = host + '/en/organisation/ccamlr-news'
        kv = {}
        succCount = 0 # 用于计数成功插入数据库的记录数量
        pageCount = getPageCount(url, kv)
        
        # 一定要指定编码方式，Python3默认是utf8，但mysql的mac版并不是
        db = pymysql.connect('127.0.0.1', 'root', 'abc', 'CourseDesign', use_unicode=True, charset="utf8")
        for i in range(pageCount): # 循环，一个一个网页顺序抓取
                kv['page'] = i
                succCount = getNewsData(url, kv, db, succCount)
        db.close()
        timeend = time.time()
        print("successd update {0} records".format(str(succCount)))
        print('last time: {0} s.'.format(timeend-timestart))

main()
        

