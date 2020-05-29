- 
  gather_facts: false
  hosts: localhost #primary_host
  remote_user: root

  tasks:
  -
    name: "SPECTRE APPLICATION [UI] PROCESS"
    shell: ps -ef | grep java | grep -v grep | grep /app/snakebite/SPECTRE_HOME/jboss | awk '{print $2}' | wc -l
    changed_when: false 
    register: spectre__process
  - 
    debug: var=spectre__process.stdout_lines

  -
    name: "SPECTRE THREAD SERVER PROCESS [ NODE 1]"
    shell: ps -ef | grep java | grep -v grep | grep /app/snakebite/SPECTRE_HOME/jboss/thread-player | awk '{print $2}' | wc -l
    changed_when: false
    register: spectre__thread__process
  -
    debug: var=spectre__process.stdout_lines


  -
    name: "RESTART SPECTRE"
    shell: echo "sh /app/skyfall/applicationScript.sh STOP"
    register: spectre__status
    when: spectre__process.stdout|int == 0 and spectre__thread__process.stdout|int == 0
  -
    debug: var=spectre__status.stdout_lines


