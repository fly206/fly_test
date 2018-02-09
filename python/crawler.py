import urllib2
import urllib
'''
post
'''
useragent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.13 Safari/537.36"
value = {"username":"fly206","password":"K139148"}
headers = {"User-Agent":useragent,"Referer":"https://www.pixiv.net/member_illust.php?mode=medium&illust_id=64154370"}
data = urllib.urlencode(value)
url = "https://www.pixiv.net/member_illust.php?mode=medium&illust_id=64154370"
request = urllib2.Request(url,data)
response = urllib2.urlopen(request)
print response.read();

'''
get
value = {}
value['username'] = "abcd"
value['password'] = "dcba"
url = "https://panbaidu.com"
geturl = url + "?" + data
request = urllib2.Request(geturl)
response = urllib2.urlopen(request)
print response.read()
'''
