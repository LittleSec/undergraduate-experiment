# -*- coding:utf-8 -*-
import os, sys
import chardet

extList = ['c', 'h', 'cpp', 'p', 'l', 'y', 'output', 'asm', 'html', 'css', 'py']
def convert(filename, out_enc="UTF8" ):
    try:
        content = open(filename, 'rb').read()
        result = chardet.detect(content)#通过chardet.detect获取当前文件的编码格式串，返回类型为字典类型
        coding = result.get('encoding')#获取encoding的值[编码格式]
        if coding not in ['utf-8', 'ascii']:#文件格式如果不是utf-8的时候，才进行转码
            print("convert: " + filename)
            print(" " + coding + " to utf-8!.....")
            new_content = content.decode(coding).encode(out_enc)
            open(filename, 'wb').write(new_content)
            print("...done!")
    except IOError as e:
    # except:
        print("error")
 
 
def explore(dir):
    for root, dirs, files in os.walk(dir):
        for file in files:
            ext = file.split('.')[-1]
            if ext.lower() in extList:
                path = os.path.join(root, file)
                convert(path)
 
def main():
    for path in sys.argv[1:]:
        if os.path.isfile(path):
            convert(path)
        elif os.path.isdir(path):
            explore(path)
 
if __name__ == "__main__":
    main()