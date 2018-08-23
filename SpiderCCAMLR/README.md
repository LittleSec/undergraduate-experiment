# SpiderCCAMLR（python爬虫抓取南极海洋生物资源保护委员会上的新闻）

>1st updated in 2017.08.30, Wednesday

>2nd updated in 2017.12.07, Thursday

1. 使用语言：Python 3.5.3，macOS Sierra 10.12.5，MySQL 14.14；用到的第三方库:requests (2.17.3), beautifulsoup4 (4.6.0), PyMySQL (0.7.11)
2. 功能：抓取`https://www.ccamlr.org/en/organisation/ccamlr-news`[（南极海洋生物资源保护委员会）](https://www.ccamlr.org/en/organisation/ccamlr-news)网站上的所有新闻的新闻数据（包括翻页），并将每一篇文章的链接、标题、时间和正文保存到MySql数据库中。
3. 技术路线：使用第三方库requests库进行网页抓取，beautifulsoup4库解析HTML网页，正则表达式提取有用的网页信息，PyMySQL库操作数据库。
4. 代码可以跨平台，运行前记得配置数据数据库（MySql）并修改main函数中的连接字符串。
