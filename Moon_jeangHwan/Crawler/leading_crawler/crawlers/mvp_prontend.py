import sys
import PyQt5
from leadingCrawler import Ui_MainWindow
from PyQt5.QtWidgets import QMainWindow
from PyQt5.QtWidgets import QApplication
from pymongo import MongoClient



# DB에 접속
def get_mongo_connection():
    client = MongoClient('localhost', 27017)  # 기본 포트
    db = client.news_database  # 데이터베이스 선택 or 생성
    return db

# 뉴스 데이터에 접근
def fetch_news_from_mongo():
    db = get_mongo_connection()
    news_collection = db.news  # 컬렉션 선택 or 생성
    return list(news_collection.find())  # 모든 뉴스 데이터를 가져옴. 차후 일정 숫자만 가져오도록 수정해야 함


class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.loadData()

    def loadData(self):
        news_data = fetch_news_from_mongo()
        # UI 버튼 리스트
        title_buttons = [self.info_title_01, self.info_title_02, self.info_title_03, self.info_title_04, self.info_title_05,
                         self.info_title_06, self.info_title_07, self.info_title_08, self.info_title_09, self.info_title_10]
        for idx, news in enumerate(news_data):
            if idx < len(title_buttons):
                title = news["title"]
                formatted_title = title[:20] + "\n" + title[20:40]
                title_buttons[idx].setText(formatted_title)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWindow = MyApp()
    mainWindow.show()
    sys.exit(app.exec_())