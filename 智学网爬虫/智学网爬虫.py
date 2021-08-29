from selenium import webdriver
import time
u=input("请输入智学网账号")
p=input("请输入密码")
url="https://www.zhixue.com/login.html"
driver=webdriver.Edge(executable_path=r'C:\Users\seewo\Desktop\msedgedriver.exe')
driver.set_window_size(0,0)
driver.get(url)
user=driver.find_element_by_name("txtUserName")
user.clear
user.send_keys(u)
pwd=driver.find_element_by_name("txtPassword")
pwd.clear
pwd.send_keys(p)
driver.find_element_by_id("signup_button").click()
time.sleep(3)
driver.find_element_by_xpath(r"//*[@id='headMenuList']/li[2]/a").click()
time.sleep(0.3)
driver.find_element_by_xpath(r"//*[@id='app']/div/div[1]/div/button").click()
time.sleep(0.3)
driver.find_element_by_xpath(r"//*[@id='app']/div/div[1]/div[2]/div[2]/img").click()
"""
//*[@id="app"]/div/div[1]/div[1]/div/div[1]/div/div/span 语文
//*[@id="app"]/div/div[1]/div[1]/div/div[2]/div/div/span 数学
//*[@id="app"]/div/div[1]/div[1]/div/div[3]/div/div/span 英语
//*[@id="app"]/div/div[1]/div[1]/div/div[4]/div/div/span 物理
//*[@id="app"]/div/div[1]/div[1]/div/div[5]/div/div/span 生物

//*[@id="app"]/div/div[1]/div[1]/div/div[6]/div/div/span 地理

//*[@id="rollTmp"]/div[1]/span
//*[@id="rollTmp"]/div[1]/span
//*[@id="rollTmp"]/div[1]/span
    
"""
time.sleep(0.3)
for i in range(1,7):
    i=str(i)
    a="//*[@id='app']/div/div[1]/div[1]/div/div["
    b="]/div/div/span"
    c=a+i+b
    driver.find_element_by_xpath(c).click()
    time.sleep(0.3)
    a_=driver.find_element_by_xpath("//*[@id='rollTmp']/div[1]/span").text
    a__=driver.find_element_by_xpath(c).text
    print("您的"+a__+"成绩为: "+a_)
    



