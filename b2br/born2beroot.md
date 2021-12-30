# Chapter 3. Born2beRoot

## 3.0. 	Useful sources
https://youtu.be/13YBlD0SOJo (Лекция от @mmargene о том как приступить к проекту)
https://youtu.be/YC5ygt5Sk3Y (Продолжение лекции от @mmargene, разбор вопросов)
https://youtu.be/7GvJaPuJ2ko (Большая лекция от @jleslee "codesshaman", разбор проекта в целом)
https://youtu.be/KYM-Dzivnjs (Что такое AppArmor и основные комманды)
https://youtu.be/1vOXUT8e8_M (Что такое GNU/Linux и его история)
 
https://gitlab.com/NickKeepKind/born2beroot

## 3.1. 	Virtualizations
 
Виртуализация - предоставление набора вычислительных ресурсов или их логического объединения, абстрагированное от аппаратной реализации, и обеспечивающее при этом логическую изоляцию друг от друга вычислительных процессов, выполняемых на одном физическом ресурсе. 

Примером использования виртуализации является возможность запуска нескольких операционных систем на одном компьютере: при том каждый из экземпляров таких гостевых операционных систем работает со своим набором логических ресурсов (процессорных, оперативной памяти, устройств хранения), предоставлением которых из общего пула, доступного на уровне оборудования, управляет хостовая операционная система — гипервизор. (Википедия)

Виртуализация == абстракция.

**UTM** 			employs Apple's Hypervisor virtualization framework.
**VirtualBox**		Oracle VM VirtualBox is a cross-platform virtualization application.

Зачем нужна виртуализация (сценарии использования):
* Запуск нескольких операционных систем одновременно.
* Более простая установка программного обеспечения (пример с почтовым сервером).
* Тестирование и аварийное восстановление (контейнер, который в том числе можно перемещать между хостами).
* Экономия на инфраструктуре (современные компьютеры используют лишь часть своей потенциальной мощности, при виртуализации можно управлять нагрузкой между виртуальными машинами).

### 3.1.1 VirtualBox

https://www.virtualbox.org/manual/ch01.html

* **Host operating system (host OS).** This is the OS of the physical computer on which Oracle VM VirtualBox was installed.
* **Guest operating system (guest OS).** This is the OS that is running inside the virtual machine.
* **Virtual machine (VM).** This is the special environment that Oracle VM VirtualBox creates for your guest OS while it is running.
* **Guest Additions.** This refers to special software packages which are shipped with Oracle VM VirtualBox but designed to be installed inside a VM to improve performance of the guest OS and to add extra features.

**Creating virtual machine**
1. Name, Machine Folder, Type, Version
> Name: <Born2beRootjmabel>
> Machine Folder </goinfre/jmabel>
> Type <Linux>
> Version <Debian (64-bit)>
2. Memory size
> RAM that should be allocated every time the VM started (not be available to host OS while the VM is running)
3. Hard Disk
> Hard disk file type
> **VDI.** Normally, Oracle VM VirtualBox uses its own container format for guest hard disks. This is called a Virtual Disk Image(VDI) file. This format is used when you create a new virtual machine with a new disk.
> **VMDK.** Oracle VM VirtualBox also fully supports the popular and open VMDK container format that is used by many other virtualization products, such as VMware.
> **VHD.** Oracle VM VirtualBox also fully supports the VHD format used by Microsoft.
4. Storage on physical hard disk
> Fixed-size. If you create a fixed-size image, an image file will be created on your host system which has roughly the same size as the virtual disk's capacity. So, for a 10 GB disk, you will have a 10 GB file. Note that the creation of a fixed-size image can take a long time depending on the size of the image and the write performance of your hard disk.
> Dynamically allocated. For more flexible storage management, use a dynamically allocated image. This will initially be very small and not occupy any space for unused virtual disk sectors, but will grow every time a disk sector is written to for the first time, until the drive reaches the maximum capacity chosen when the drive was created. While this format takes less space initially, the fact that Oracle VM VirtualBox needs to expand the image file consumes additional computing resources, so until the disk file size has stabilized, write operations may be slower than with fixed size disks. However, after a time the rate of growth will slow and the average penalty for write operations will be negligible.
5. File location and size
> 30.8 GB
> Для измерения при этом применяет степень числа 2. Следовательно, здесь должно быть Мибибайты.
4. Выбираем образ операционной системы
> Settings->Storage->Optical Drive

## 3.2. 	Debian GNU/Linux installer (BIOS mode)
 
BIOS (basic input/output system -  «базовая система ввода-вывода»), — набор микропрограмм, реализующих API для работы с аппаратурой компьютера и подключенными к нему устройствами.
 
**Debian** and **CentOS** -  free and open source software.

**Why not CentOS**: 
CentOS, because will be no CentOS Linux—instead, there will (only) be CentOS Stream (https://blog.centos.org/2020/12/future-is-centos-stream/)
CentOS Stream - Continuously delivered distro that tracks just ahead of Red Hat Enterprise Linux (RHEL) development, positioned as a midstream between Fedora Linux and RHEL.
This will be the final release of CentOS Linux 8, which is going End Of Life (EOL) on December 31, 2021. We recommend that users of CentOS Linux 8 migrate to CentOS Stream 8.
 
Download Debian официальные образы стабильного выпуска:
https://www.debian.org/CD/http-ftp/index.ru.html#stable
 
Why Debian:
1. For users:
> Free software
> Stable and secure (a wide range of devices including laptops, desktops and servers)
> Extensive Hardware Support. Most hardware is supported by the Linux kernel.
> Many popular Linux distributions, like Ubuntu, Knoppix, PureOS or Tails, are based on Debian.
> The Debian Project is a Community.
2. For developers:
> Multiple Hardware Architectures
> IoT and Embedded Devices
> Different Releases and Public Bug Tracker

**Debian GNU/Linux Installation Guide**
https://www.debian.org/releases/stable/amd64/index.en.html

**Hostname** - identifies your system to the network.

### 3.2.1 Partition disks
 
SATA - последовательное AT подключение - стандартный тип дисков на многих компьютерах, интерфейс обмена данными с накопителями информации.
 
1. Жесткий диск может быть разделен на 4-ре основных (первичных) раздела: sda1, sda2,sda3, sda4 или sdb1, sdb2 и т.д.
2. Один из основных разделов одного жесткого диска можно сделать расширенным. Только один. Расширенный раздел можно разделить уже на много частей (на 63 логических дисков).
3. Так как основных разделов для одного жесткого диска может быть только 4-ре, то система резервирует для них имена, например sda1, sda2, sda3, sda4. Получается, что первый созданный логический раздел получит имя sda5. Можно разбить так:
* sda1 основной раздел
* sda2 расширенный раздел
* sda5 первый логический диск в расширенном разделе
* sda6 второй логический диск в расширенном разделе
* sda3 основной раздел
Источник: http://rskl.ru/disk_parted/
 
**Partition disks**
* /				the root file system
* /boot			static files of the boot loader (allows your system to boot DebianLinux)
* /home			user home directories
* /tmp			temporary files
* /usr			static data (исполняемые файлы и общие ресусы, не являются критическими для системы)
* /var			variable data (файлы в изменяемом состоянии, файлы с изменяющимся размером)
* /srv			data fir services privided by the system (данные системных служб);
* /opt			add-on application software packages (дополнительное программное обеспечение, установка более крупных программ вместо /usr)

**Файловая система**
* Ext2		Вторая расширенная файловая система — используется во многих дистрибутивах Linux. (для boot и tmp)
* Ext4		Журналируемая (Добавлена функция ведения журнала.)

**Partitions**
	lsblk
* MAJ		номер драйвера, который используется в системе
* MIN		у этого драйвера есть идентификатор потока
* SIZE		в мебибайтах (степень числа 2)
* RM		RAM disk

**LVM (Logical Volume Manager)**, менеджер логических томов - это система управления дисковым пространством, абстрагирующаяся от физических устройств. 

**Точка монтирования (англ. mount point)** — это каталог или файл, с помощью которого обеспечивается доступ к новой файловой системе, каталогу или файлу.

## 3.4. 	Operating system random questions
 
**Aptitude and apt** - менеджеры пакетов (tools handle package management).
Синтаксис aptitude более лаконичный.
По умолчанию apt входит в стандартные утилиты, aptitude следует установить:
	apt-get install sudo
	apt-get install aptitude

**Selinux** CetOS и  **AppArmor** - это модуль безопасности ядра Linux, который позволяет системному администратору ограничивать возможности программ c помощью профилей для каждой программы.

## 3.5. 	SSH service
 
**SSH (Secure Shell - безопасная оболочка)** - сетевой протокол прикладного уровня, обеспечивается безопасное соединение с удалённой машиной.
Обмен данными по сети ведётся между двумя процессами по определённому протоколу. Для установки соединения необходимы:
* номер протокола;
* два IP-адреса (адрес хоста-отправителя и адрес хоста-получателя для построения маршрута между ними);
* два номера порта (порт процесса-отправителя и порт получателя).

A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.
	vim /etc/ssh/sshd_config
 
В sshd_config изменяем:
	Port 4242
	#Authentication
	PermitRootLogin no
 
Далее restart the SSH server. Прописываем порт 4242 в настройках VirtualBox.
	service sshd restart

Вход  в ОС через терминал:
	ssh user@localhost -p 4242

Проверить, что SSH запущен
	sudo service ssh status

## 3.6. 	Firewall
Firewall (брандмауэр) - защита между глобальным интернетом и локальной компьютерной сетью организации. Он выполняет функцию проверки и фильтрации данных, поступающих из интернета. В зависимости от настроек брандмауэр может пропустить их или заблокировать.

	apt-get install ufw
	ufw status
	sudo ufw status numbered
	ufw enable
	ufw disable
	cat /etc/default/ufw
	ufw allow 4242
	ufw status
	sudo ufw delete 3

В настройках машины в Virtual Box добавить порт в "Host Port" и "Guest Port"
Settings->Network

## 3.7. 	Hostname

	vim /etc/hostname
	vim /etc/hosts
	reboot now

## 3.8. 	Users and groups

Создать пользователя
	adduser new_user

Удалить пользователя
	userdel new_user

**Groups**
* daemon - от имени этой группы и пользователя daemon запускаютcя сервисы, которым необходима возможность записи файлов на диск.
* sys - группа открывает доступ к исходникам ядра и файлам include сохраненным в системе
* sync - позволяет выполнять команду /bin/sync
* games - разрешает играм записывать свои файлы настроек и историю в определенную папку
* man - позволяет добавлять страницы в директорию /var/cache/man
* lp - позволяет использовать устройства параллельных портов
* mail - позволяет записывать данные в почтовые ящики /var/mail/
* proxy - используется прокси серверами, нет доступа записи файлов на диск
* www-data - с этой группой запускается веб-сервер, она дает доступ на запись /var/www, где находятся файлы веб-документов
* list - позволяет просматривать сообщения в /var/mail
* nogroup - используется для процессов, которые не могут создавать файлов на жестком диске, а только читать, обычно применяется вместе с пользователем nobody.
* adm - позволяет читать логи из директории /var/log
* tty - все устройства /dev/vca разрешают доступ на чтение и запись пользователям из этой группы
* disk - открывает доступ к жестким дискам /dev/sd* /dev/hd*, можно сказать, что это аналог рут доступа.
* dialout - полный доступ к серийному порту
* cdrom - доступ к CD-ROM
* wheel - позволяет запускать утилиту sudo для повышения привилегий
* audio - управление аудиодрайвером
* src - полный доступ к исходникам в каталоге /usr/src/
* shadow - разрешает чтение файла /etc/shadow
* utmp - разрешает запись в файлы /var/log/utmp /var/log/wtmp
* video - позволяет работать с видеодрайвером
* plugdev - позволяет монтировать внешние устройства USB, CD и т д
* staff - разрешает запись в папку /usr/local
Источник: https://losst.ru/gruppy-polzovatelej-linux

**Создать группу**
	sudo groupadd user42

**Добавить пользователя в группу**
usermod -a - Append the user  to the supplementary group (use only with -G)
	sudo usermod -a -G user42 jmabel

Проверить, состоит ли пользователь в группе:
	groups jmabel
	cat /etc/group | grep jmabel

## 3.9. 	Password policy 

Поставить: 
	apt-get install libpam-pwquality
Далее установить параметры времени существования пароля:
	vim /etc/login.defs
	PASS_MAX_DAYS 30
	PASS_MIN_DAYS 2
	PASS_WARN_AGE 7

Проверка:
	sudo chage -l jmabel

Установить параметры содержания пароля: 
	vim /etc/pam.d/common_password

* retry=3: Prompt a user 3 times before returning with error.
* minlen=10 : The password length cannot be less than this parameter
* maxrepeat=3: Allow a maximum of 3 repeated characters
* ucredit=-1 : Require at least one uppercase character
* lcredit=-1 : Must have at least one lowercase character.
* dcredit=-1 : must have at least one digit
* difok=7 : The number of characters in the new password that must not have been present in the old password.
* reject_username: Rejects the password if contains the name of the user in either straight or reversed form.
* enforce_for_root: Enforce pasword policy for root user

	password	requisite			pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root

Поменять пароль:
	sudo passwd user

## 3.10. 	Configuration for sudo group 

**Sudo** allows a permitted users to execute a commands a root (or another user) as specified by the security policy.

Looks up invokimg users and its permissions
	cat /etc/sudoers

Редактируется только через visudo
	visudo /etc/sudoers

	Defaults	env_reset // сбрасывает среду терминала, удаляя пользовательские переменные
	Defaults	mail_badpass
	Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
	Defaults	badpass_message="Don't give up and try again!"
	Defaults	passwd_tries=3
	Defaults	logfile="/var/log/sudo/sudo.log"
	Defaults	log_input,log_outputsudo visudo
	Defaults	requiretty // The TTY mode has to be enabled for security reasons.

Создать папку и файл, куда будут записываться логи:
	mkdir /var/log/sudo
	touch /var/log/sudo/sudo.log

Проверить, создаются ли логи:
	sudo cat /var/log/sudo/sudo.log

Require tty: Why use tty? If some non-root code is exploited (a PHP script, for example), the requiretty option means that the exploit code won't be able to directly upgrade its privileges by running sudo.

Snap-пакет — это пакет, который помимо готовой сборки самого приложения, включает в себя все необходимые зависимости и может работать (почти) в любом дистрибутиве Linux.

## 3.11	Script monitorint.sh

Report file system disk space usage, size MiB=M
	df -bm
Display amount of free and used memory in the system, in mebibytes.
	free -m

Query the systemd journal  
	journalctl  

Show or set the system's host name; Display all network addresses of the host.
	hostname -I

List block devices (partitions) 
	lsblk

Print system information 
	uname		

Print the user names of users currently logged in to the current host 
	users

Display Linux processes; starts top in Batch mode until the iterations limit
	top	-bn1

Print newline, word, and byte counts for each file 
	wc -l	// print the newline counts
	wc -w	// print the word counts		

Show who is logged on; -b time of last system boot
	who	-b		

Сетевые подключения:
	/proc/net/sockstat

Информация о CPU:
	/proc/cpuinfo

**awk**		pattern scanning and text processing language
**END**		предопределенный шаблон, выполняется после обработки последней записи входного потока.

**Transmission Control Protocol (TCP, протокол управления передачей)** — один из основных протоколов передачи данных интернета. Предназначен для управления передачей данных интернета. 
**Sockstat** is a tool to let you view information about open connections.
	sudo cat /proc/net/sockstat
 
**MAC (Media Access Control)**  - нижний подуровень канального (второго) уровня модели OSI.

## 3.12 Планировщик Cron

The -e option is used to edit the current crontab using the editor specified by the VISUAL or EDITOR environment variables.
The -l option causes the current crontab to be displayed on standard output. 
	crontab -e

To schedule a shell script to run every 10 minutes, replace below line
	# m h  dom mon dow   command
 with:
	*/10 * * * * sh /path/to/script

Остановить выполнение запуска:
	systemctl stop cron

-r      Remove the current crontab.
	crontab -r

* m - Minute - 0 through 59
* h - Hour - 0 through 23
* dom - Day of Month - 0 through 31
* mon - Month - 0 through 12
* dow - Day of Week - 0 through 7 (0 and 7 are both Sunday)

## 3.13 Set up WordPress website

Set up a functional WordPress website with the following services: lighttpd, MariaDB, and PHP.

* **lighttpd** — веб-сервер
* **MariaDB** — ответвление от системы управления базами данных MySQL, разрабатываемое сообществом под лицензией GNU GPL.
* **PHP** — скриптовый язык общего назначения, интенсивно применяемый для разработки веб-приложений. 

**Step 1. Installing Lighttpd**

	sudo apt install lighttpd

Verify whether lighttpd was successfully installed
dpkg - package manager for Debian	
	dpkg -l | grep lighttpd

Allow incoming connections using Port 80
	sudo ufw allow 80

**Step 2: Installing & Configuring MariaDB**

Install mariadb-server
	sudo apt install mariadb-server

Verify whether mariadb-server was successfully installed
	dpkg -l | grep mariadb-server

Настройка (везде yes, кроме установки пароля рута и в первом запросе нажать Enter)

Входим в оболочку MariaDB:
	mariadb

Создаем БД:
	CREATE DATABASE wordpress;

Создаем пользователя для БД:
	CREATE USER 'jmabel'@'localhost' IDENTIFIED BY '<password>';

Предоставляем пользователю полные привелегии для БД:
	GRANT ALL ON wordpress.* TO 'jmabel'@'localhost';
	FLUSH PRIVILEGES;

	exit

Проверка пользователя:
	mariadb -u <user> -p

Проверка БД:
	SHOW DATABASES;

**Step 3: Installing PHP**

Install php-cgi & php-mysql 
	sudo apt install php-cgi php-mysql

Verify whether php-cgi & php-mysql was successfully
	dpkg -l | grep php

**Step 4: Downloading & Configuring WordPress**

Install wget
	sudo apt install wget

Download WordPress
	sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html

Extract downloaded content
	sudo tar -xzvf /var/www/html/latest.tar.gz /var/www/html/

Remove tarball
	sudo rm /var/www/html/latest.tar.gz

Copy content of /var/www/html/wordpress to /var/www/html
	sudo cp -r /var/www/html/wordpress/* /var/www/html

Remove /var/www/html/wordpress
	sudo rm -rf /var/www/html/wordpress

Create WordPress configuration file from its sample
	sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

Configure WordPress to reference previously-created MariaDB database & user
	sudo vi /var/www/html/wp-config.php

Replace the below
	23 define( 'DB_NAME', 'database_name_here' );^M
	26 define( 'DB_USER', 'username_here' );^M
	29 define( 'DB_PASSWORD', 'password_here' );^M
 
with:
	23 define( 'DB_NAME', '<database-name>' );^M
	26 define( 'DB_USER', '<username-2>' );^M
	29 define( 'DB_PASSWORD', '<password-2>' );^M

**Step 5: Configuring Lighttpd**

Enable below modules
	sudo lighty-enable-mod fastcgi
	sudo lighty-enable-mod fastcgi-php
	sudo service lighttpd force-reload

**Step 6: Wordpress**
Далее в браузере заходим в localhost:80
Site Title	Born2BeRootjmabel
Username	jmabel
Password	^V&aHm%TDOzcxDi@YP

## 3.14  Set up a service

Отправка почты из командной строки (консоли) Linux:
https://winitpro.ru/index.php/2021/04/21/otpravka-email-iz-konsoli-linux/

Для отправки почты из командной строки Linux вам нужно установить Mail User Agent, которые умеет подключаться к smtp серверам для отправки и получения почты.

Установка утилиты mail (mailx)
	sudo apt-get install mailutils

Установить почтовый сервер:
	sudo apt install sendmail -y

Основные опции при отправке писем:
* -s — Subject:
* -c — Cc:
* -b — BCc:
* -r — From:

Отправить простое сообщение из консоли Linux
	echo "Hello world from jmabel" | mail -s "Testing mail service" korshunovamr@gmail.com
 
 ## 3.15 Signature of machine’s virtual disk
 
 	shasum /goinfre/jmabel/Born2beRootjmabel/Born2beRootjmabel.vdi

d2a6aa5d517e5e1e8bb8fbb1d5cf2b137b6eb928