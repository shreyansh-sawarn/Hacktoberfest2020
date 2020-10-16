'''
Script to scrap the headlines of BBC News website home page using 
Requests and BeautifulSoup module of Python
'''

import requests
from bs4 import BeautifulSoup
import pprint  # To print the result in prettify manner

response = requests.get("https://www.bbc.com/")

parsed_html = BeautifulSoup(response.text,'html.parser')

headlines_links = parsed_html.select('.media__link')

def bbcHeadlines(headlines_links):
    news = []
    for links in headlines_links:
        headlines = links.get_text('\n',strip=True)
        if links.get('href').startswith('https'):
            link = links.get('href')
            news.append({'HeadLines ':headlines, 'Link': link})
        else:
            link = links.get('href')
            news.append({'HeadLines ': headlines, 'Link': 'https://www.bbc.com'+link})

    return news

pprint.pprint(bbcHeadlines(headlines_links))
