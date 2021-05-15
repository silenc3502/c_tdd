
# CICD

## How to Set Environment

```make
wget -q -O - https://pkg.jenkins.io/debian/jenkins.io.key | sudo apt-key add -
echo deb http://pkg.jenkins.io/debian-stable binary/ | sudo tee /etc/apt/sources.list.d/jenkins.list
sudo apt-get update
sudo apt-get install jenkins
```

## Access to Jenkins

http://localhost:8080/  

## Check Initial Password

```make
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
```

## Add Jenkins Plugin

```make
1. http://localhost:8080/manage 접속
2. Manage Plugins 클릭
3. Git, Cobertura, JUnit 플러그인 설치
4. 재시작 없이 설치하기
5. Restart Jenkins when installation is complete and no jobs are running 체크
```

## Set SCons Build System

```make
sudo apt-get install scons
```

## How to Install gcovr

```make
1. wget https://github.com/gcovr/gcovr/archive/refs/tags/3.2.tar.gz
2. tar zxvf 3.2.tar.gz
3. cd gcovr-*.*/scripts
4. chmod +x gcovr
5. sudo mv gcovr ~/bin/
```

## Register SCM

```make
1. mkdir -p ~/proj/jenkins_test
   2번을 위해 당연히 clone 받는다.
2. cd ~/proj/jenkins_test/cicd_add
   여기서 cicd_add는 미리 git에 만들어둬야 한다.
3. git init --bare --shared=true
4. add 프로그램이 있는 위치로 이동한다.
5. git init
6. git remote add origin (http)~~cicd_add.git
7. git add SConstruct src
8. git commit -m "init repo"
9. git push origin master
```

## Create Jenkins Job

```make
1. localhost:8080/newJob 으로 이동한다.
2. Enter an item name에 cicd_add를 적는다.
3. Freestyle project를 선택하고 OK를 누른다.
4. General -> Source Code Management -> Git 선택
5. 앞서 만든 cicd_add.git 주소를 연결한다.
6. Build Triggers -> Poll SCM 체크
7. Schedule 부분에 * * * * *을 써 넣는다(1분에 1회씩 레포 갱신 확인)
8. Build -> Add build step -> Execute Shell을 선택한다.
9. Command에 scons 입력
10. Save 눌러서 종료
11. 좌측의 Build Now 링크를 클릭해보자!
12. Build가 실패하여 Build History에 빨간색 동그라미가 표시됐을텐데 눌러보자!
13. Console Output 링크를 클릭한다.
14. 살펴보면 에러메시지의 원인은 gcovr을 찾을 수 없다에 해당한다.
15. apt-get 으로 jenkins를 설치하였다면 사용자 권한으로 실행된다.
    그러므로 빌드에 사용하는 명령은 jenkins 사용자에게 보여야 하며
    그렇기 때문에 gcovr을 /usr/local/bin 아래로 이동시켜야 한다.
    sudo mv ~/bin/gcovr /usr/local/bin/
16. gcovr 파일을 이동시킨 이후 다시 Build Now를 클릭해보자!
17. 성공적으로 처리되었다면 파랑색 동그라미가 나타나며
    Configuration -> 하단의 Post-build Actions -> Publish JUnit test result report 를 선택한다.
18. Test report XMLs 에 test_report.xml을 입력한다.
19. 다시 한 번 Post-build Actions -> Publish Cobertura Coverage Report를 추가한다.
20. Coberturaxml report pattern 에 coverage.xml을 입력한다.
21. 저장 버튼을 누르고 Build Now를 누른다.
22. 여전히 오류가 발생하며 Console Output을 보면 아래와 같은 메시지가 나타난다.
    For example, /var/lib/jenkins/workspace/cicd_add/test_report.xml is 20 min old
    SCons는 필요한 최소한의 빌드만 수행하므로 테스트 보고서가 오래되었다고 불만을 토로하는 것이다.
    make clean에 해당하는 것이 scons -c에 해당한다.
23. 다시 Configuration -> Build -> Execute Shell -> Command에 아래와 같이 작성한다.
    scons -c
    scons
24. 이제 다시 Build를 해보면 성공하는 것을 볼 수 있을 것이다.
25. 파랑색 동그라미를 눌러서 테스트 결과나 커버리지를 통해 실행된 위치까지 확인이 가능하다.
26. 실패하는 테스트를 작성하여 테스트 해보면 변경 파일이 나타나며 실패 내역등등을 살펴볼 수 있다.
```
