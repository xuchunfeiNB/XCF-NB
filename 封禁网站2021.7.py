# editor: Fei (@copyright)
# time: 2021.7.2 11:00

import time
import urllib.request
url_1=input("请输入您要封禁的网址（域名部分+虚拟目录部分）不要协议!")
url_2=" 127.0.0.1 "+str(url_1)
opener=urllib.request.build_opener()
with open('C:\Windows\System32\drivers\etc\hosts','a') as f:
    try:
        f.write(url_2)
        f.write('\r\n')
        f.close()
        print("正在测试是否成功……")
        try:
            opener.open(("https://"+url_1))
            time.sleep(5)
            print("未知的错误！请手动登入检查是否成功封禁或检查输入的网址是否有误！")
        except urllib.error.HTTPError:
            print("封禁成功!")  
            time.sleep(2)   
        except urllib.error.URLError:
            print("封禁成功!")
            time.sleep(2)
    finally:
        if f:
            f.close()
            

    
