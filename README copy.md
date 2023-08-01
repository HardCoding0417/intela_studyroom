
# [Intel] Edge AI SW Academy (2023-07-04 ~ 2024-01-30)

수업을 들으면서 작성할 소스코드나 자료들을 저장할 원격 저장소입니다.

## GitHub 사용의 이점

- 언제 어디서든 인터넷만 된다면 자료에 접근할 수 있습니다.
- 스터디나 프로젝트, 학습자료 등을 공유할 수 있습니다.
- 서로의 코드를 리뷰해줄 수 있습니다.

## 목차

- 1. 설치와 세팅
- 2. 사용순서

### 1. 설치와 세팅

#### Git 설치 파일 다운로드

1. <a href = "https://git-scm.com" target = "_blank">Git 홈페이지</a>에 들어갑니다.
2. 화면 우측 중앙에 나오는 모니터의 'Download for Windows' 버튼을 클릭합니다.
3. 제목(Download for Windows) 바로 아래에 있는 'Click here to download' 링크를 클릭합니다.

#### Git 설치

아래에 보이는 두 사진의 옵션을 제외하고는
모두 Next로 넘어간 뒤 Install로 설치 진행해주세요.

    ![2-1_Choosing_default_editor](img/2-1_Choosing_default_editor.png)
- **Choosing the default editor used by Git**  
    Use Visual Studio Code as Git's default editor
    ![2-2_initial_branch](img/2-2_initial_branch.png)
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

#### 사용자 이름과 이메일 입력하기

<code>Ctrl + \`</code>로 터미널 창을 열어서 다음 두 명령어를 입력합니다.  

```
git config --global user.name "사용자 이름"  
git config --global user.email "이메일 주소"
```

버전을 관리할 때 같이 기록되는 정보들입니다.  
정보를 입력하지 않으면 버전 관리를 할 수 없으니 꼭 입력해주세요.

#### 내 branch 만들기

1. 원격 저장소를 복제해오면서 만든 'intela_studyroom' 지역 저장소 폴더가 Visual Studio Code에서 열려있는 상태입니다.
2. `Ctrl + Shift + G` 혹은 왼쪽의 아이콘들 중 세번째 아이콘을 클릭합니다.

    ![Source Control button](img/Source%20Control%20button.png)
3. 아래 사진과 같이 'Create Branch...'를 찾아 클릭합니다.

    ![Create Branch...](img/Create%20Branch....png)
4. 붙임표(-)나 밑줄(_)을 이용해서 자신의 영어 이름을 입력합니다.  
    예시) Hong-Gildong
5. 왼쪽 아래에 해당 이름으로 branch가 변경됨을 확인할 수 있습니다.  
    앞으로는 기존의 'main' branch가 아닌 자신이 새로 만든 브랜치에서 작업하면 됩니다.


여기까지 마치셨다면 깃과 깃허브를 사용할 준비가 끝난 것입니다.

이제 사용 순서를 알아보겠습니다.

---

### 2. 내 코드를 깃헙에 올려보자!

순차적으로 따라하시면 사용법을 익히실 수 있도록 구성했습니다.

#### 2-1 커밋하기

    하나씩 따라하면서 천천히 알아봅시다.

1. 먼저, 로컬 저장소에서 코드를 변경합니다.

    ![2-3_local_repository](img/2-3_local_repository.png)

    파란색 동그라미로 표시된 Explorer를 클릭하시면
    초록색 선으로 줄쳐진 INTELA_STUDYROOM 폴더가 보이실 겁니다.    
    이 폴더가 여러분의 local repository입니다.

    아무 코드나 업로드해보세요. 사진 같은 걸 올리셔도 좋습니다.

2. 로컬 저장소에서 코드를 변경하면 소스 컨트롤 버튼에 알람이 들어올 겁니다.

    ![Source Control button](img/Source%20Control%20button.png)

    소스 컨트롤을 클릭해보세요.

3. 그런 다음, 아래 사진과 같이 'Changes' 옆의 플러스(+) 아이콘을 찾아 클릭해줍니다.

    ![Stage All Changes](img/Stage%20All%20Changes.png)

    +버튼을 누르면 변경사항(Changes)에 있던 소스파일이
    아래 사진과 같이 Staged Change 탭으로 이동한 것을 확인할 수 있으실 겁니다.
    
    ![2-3_stage_changes](img/2-3_stage_changes.png)

    여기까지의 작업을 스테이징이라고 합니다.


4. 스테이징이란 커밋을 준비하는 단계로, 

    ![2-5_commit](img/2-5_commit.png)

    1번에 메세지를 입력 후
    2번의 커밋 버튼을 클릭하면

    스테이징된 변경사항들이 커밋됩니다. (스테이징되지 않은 변경사항들은 커밋되지 않습니다)

5. 이제, `Ctrl + S`로 저장 후 `Ctrl + W`로 창을 닫아봅시다.
    창을 닫으면 commit이 진행되고 버전이 만들어집니다.


#### 2-2 버전 확인하기

---

### 원격 저장소에 버전 올리고 가져오기

#### push / 원격 저장소에 새로 만든 버전 적용하기

1. 아래 사진과 같이 'Push to...'를 찾아 클릭합니다. 명령 창이 뜨고 Enter를 누르면 push가 완료됩니다.

    ![Push to...](img/Push%20to....png)
2. <a href = "https://github.com/HardCoding0417/intela_studyroom" target = "_blank">원격 저장소</a>에서 아래 사진과 같이 자신이 만든 branch를 찾아 클릭합니다.

    ![own branch at origin](img/own%20branch%20at%20origin.png)
3. 파일들이 제대로 업로드 되었나 확인합니다.

#### pull / 원격 저장소의 변경사항을 지역 저장소에 적용

원격 저장소(특정 branch)의 변경사항을 지역 저장소로 불러오는 일은 pull 명령을 통해서 행할 수 있습니다.

지금은 원격 저장소의 버전과 지역 저장소의 버전이 일치하기 때문에 pull을 할 필요가 없지만(해도 변경사항이 없지만), 지금 사용 중인 컴퓨터가 아닌 다른 컴퓨터에서 원격 저장소의 버전을 수정했을 경우 수정 사항을 반영하기 위해 pull이 반드시 필요합니다.

1. 아래 사진과 같이 'Pull from...'을 찾아 클릭합니다.

    ![Pull from...](img/Pull%20from....png)
2. 'origin/`자신이 만든 branch 이름`'을 선택합니다.

---

### 다른 컴퓨터에서의 원격 저장소 접근

집이나 기숙사에 가서 원격 저장소에 올려진 버전을 다운받아 수정하고 다시 버전을 만들어 업로드 하고 싶다면 다음의 순서를 다시 따릅니다.

```
- Git 설치 파일 다운로드
- Git 설치
- 원격 저장소를 지역 저장소로 복제해오기
- 사용자 이름과 이메일 입력하기
- 내 branch 만들기
- pull / 원격 저장소의 변경사항을 지역 저장소에 적용
- 지역 저장소에서 간단하게 버전 관리하기
- push / 원격 저장소에 새로 만든 버전 적용하기
```