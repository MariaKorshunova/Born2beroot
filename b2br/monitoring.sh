#The architecture of your operating system and its kernel version.
#The number of physical processors.
#The number of virtual processors.
#The current available RAM on your server and its utilization rate as a percentage.
#The current available memory on your server and its utilization rate as a percentage.
#The current utilization rate of your processors as a percentage.
#The date and time of the last reboot.
#Whether LVM is active or not.
#The number of active connections.
#The number of users using the server.
#The IPv4 address of your server and its MAC (Media Access Control) address.
#The number of commands executed with the sudo program."
USED_RAM=$(free -m | awk '$1 == "Mem:"{print $3}')
TOTAL_RAM=$(free -m | awk '$1 == "Mem:"{print $2}')
USED_MEMORY=$(df -Bm | grep '^/dev' | grep -v 'boot' | awk '{ u += $3} END { print u }')
TOTAL_MEMORY=$(df -Bm | grep '^/dev' | grep -v 'boot' | awk '{ t += $4} END { print t }')
wall "#Architecture: $(uname -a)
#CPU physical : $(grep "physical id" /proc/cpuinfo | uniq | wc -l)
#vCPU : $(grep "^processor" /proc/cpuinfo | wc -l)
#Memory Usage: $USED_RAM/$((TOTAL_RAM))MB ($(printf %.2f%% $(((1000000000*USED_RAM)/TOTAL_RAM))e-7))
#Disk Usage: $USED_MEMORY/$((TOTAL_MEMORY/1024))Gb ($(printf %.2f%% $(((1000000000*USED_MEMORY)/TOTAL_MEMORY))e-7))
#CPU load: $(top -bn1 | grep '^%Cpu(s)' | awk '{ printf("%.1f%%", ($2 + $4 + $6)) }') 
#Last boot: $(who -b | awk '{print $3 " " $4}')
#LVM use: $(if [ $(lsblk | grep lvm | wc -l) -ne 0 ]; then echo yes; else echo no; fi)
#Connexions TCP : $(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}') ESTABLISHED
#User log: $(users | wc -w)
#Network: IP $(hostname -I)($(ip link show | awk '$1=="link/ether"{print $2}'))
#Sudo : $(journalctl _COMM=sudo | grep COMMAND | wc -l) cmd"