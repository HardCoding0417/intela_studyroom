import requests
import urllib.request
import zipfile


url = 'https://storage.googleapis.com/laurencemoroney-blog.appspot.com/'
file_name = 'horse-or-human.zip'
training_dir = './dataset/'

# urllib.request.urlretrieve(url + file_name, file_name)

# zip_ref = zipfile.ZipFile(file_name, 'r')
# zip_ref.extractall(training_dir)
# zip_ref.close()
