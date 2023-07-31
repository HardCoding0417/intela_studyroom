
# [Intel] Edge AI SW Academy (2023-07-04 ~ 2024-01-30)

해당 과정 수업을 들으면서 생겨나는 소스코드나 자료들을 저장할 원격 저장소입니다.

### GitHub 사용의 이점

- 클라우드 서비스나 USB를 사용하지 않아도 언제 어디서든 인터넷만 있다면 자료에 접근할 수 있습니다.
- 수업을 따라가다 적지 못한 부분이 있을 때 나중에 다른 사람의 자료를 참고할 수 있습니다.
- 다른 사람의 코드를 리뷰할 수 있습니다.

## 사용법

### 초기 세팅

#### Git 설치 파일 다운로드

1. <a href = "https://git-scm.com" target = "_blank">Git 홈페이지</a>에 들어갑니다.
2. 화면 우측 중앙에 나오는 모니터의 'Download for Windows' 버튼을 클릭합니다.
3. 제목(Download for Windows) 바로 아래에 있는 'Click here to download' 링크를 클릭합니다.

#### Git 설치

아래에 있는 요소를 제외하고는 모두 Next로 넘어간 뒤 Install로 설치 진행해주세요.

- **Choosing the default editor used by Git**  
    Use Visual Studio Code as Git's default editor
- **Adjusting the name of the initial branch in new repositories**  
    Override the default branch name for new repositories  
    (입력 창은 main 그대로 놔 두세요)

설치가 완료되셨다면 'View Release Notes'를 체크 해제하시고 Finish 누르시면 됩니다.  
만약 Visual Studio Code가 켜져 있는 상태라면 Git을 인식할 수 있도록 껐다가 다시 켜주세요.

#### GitHub 계정 만들기

1. <a href = "https://github.com" target = "_blank">GitHub 홈페이지</a>에 들어갑니다.
2. 오른쪽 위의 'Sign Up' 버튼을 클릭합니다.
3. email(이메일), password(비밀번호), username(사용자 이름)을 차례로 입력합니다.
4. GitHub 공지사항을 이메일로 받고 싶다면 'y', 아니라면 'n'을 입력합니다.
5. 퍼즐을 풀고 'Create Account' 버튼을 클릭합니다.
6. 입력한 이메일로 온 코드를 입력하세요. 완료되면 창을 닫아도 좋습니다.

#### 원격 저장소를 지역 저장소로 복제해오기

1. <a href = "https://coding-factory.tistory.com/940" target = "_blank">이 게시글</a>의 1~7 과정을 따라합니다.
2. 'Intela_studyroom'을 입력해서 'HardCoding0417/intela_studyroom' 항목을 찾아 Enter를 누릅니다.
3. 지역 저장소 폴더를 만들 위치를 지정해줍니다. 보통 'C:\\Users\\`계정명`\\'에 저장합니다.
4. 'Open' 버튼을 눌러 현재 창에서, 혹은 'Open in New Window' 버튼을 눌러 새 창에서 지역 저장소 폴더를 엽니다.
5. 'Do you trust the authors of the files in this folder?' 팝업이 뜨면 'Yes, I trust the authors' 버튼을 누릅니다.

#### 내 branch 만들기

1. 원격 저장소를 복제해오면서 만든 'intela_studyroom' 지역 저장소 폴더가 Visual Studio Code에서 열려있는 상태입니다.
2. `Ctrl + Shift + G` 혹은 왼쪽의 아이콘들 중 세번째 아이콘을 클릭합니다.

    ![Source Control button](Source%20Control%20button.png)
3. 아래 사진과 같이 'Create Branch...'를 클릭합니다.

    ![Create Branch...](Create%20Branch....png)
4. 붙임표(-)나 밑줄(_)을 이용해서 자신의 영어 이름을 입력합니다.  
    예시) Hong-Gildong
5. 왼쪽 아래에 해당 이름으로 branch가 변경됨을 확인할 수 있습니다.  
    앞으로는 기존의 'main' branch가 아닌 자신이 새로 만든 브랜치에서 작업하면 됩니다.

#### 사용자 이름과 이메일 입력하기

<code>Ctrl + \`</code>로 터미널 창을 열어서 다음 두 명령어를 입력합니다.  

> `git config --global user.name "`사용자 이름`"`  
> `git config --global user.email "`이메일 주소`"`

버전을 관리할 때 같이 기록되는 정보들입니다.  
정보를 입력하지 않으면 버전 관리를 할 수 없으니 꼭 입력해주세요.

---

### 지역 저장소에서 간단하게 버전 관리하기

1. 지금까지 수업을 들으면서 만들었던 소스코드나 자료들을 지역 저장소 폴더로 복사합니다.  
    복사한 파일들을 나중에 원격 저장소에 올릴 예정이니 공유하고 싶지 않은 파일들은 제외시키면 됩니다.
2. 아래 사진과 같이 'Changes' 옆의 플러스(+) 아이콘을 클릭합니다.

    ![Stage All Changes]()
3. 그 위의 'Commit' 버튼을 누릅니다.
4. 'COMMIT_EDITMSG' 창이 뜨면 첫 번째 줄에 원하는 메시지를 입력합니다.  
    예시) Python 수업 코드 추가, OO 프로젝트 폴더 생성, ...
5. `Ctrl + S`로 저장 후 `Ctrl + W`로 창을 닫습니다. 창을 닫으면 commit이 진행되고 버전이 만들어집니다.

---

### 원격 저장소에 파일 올리기

#### push - 원격 저장소에 새로 만든 버전 적용하기

1. 아래 사진과 같이 'Push to...'를 클릭합니다. 명령 창이 뜨면 Enter를 누릅니다.

    ![Push to...]()
2. 




#### pull - 원격 저장소의 변경사항을 지역 저장소에 적용

지역 저장소의 수정사항을 원격 저장소에 반영하기 전에 해야 할 일은 원격 저장소의 변경사항을 불러오는 일입니다.  
이 일은 pull 명령을 통해서 행할 수 있습니다.

1. 