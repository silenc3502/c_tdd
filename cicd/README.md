
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
3. Git, Cobertura 플러그인 설치
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
