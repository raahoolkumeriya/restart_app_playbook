-
  gather_facts: false
  hosts: localhost #primary_host,secondary_host,tertiary_host,quaternary_host
  remote_user: root

  tasks:
  -
    name: "SKYFALL PROCESS [ ALL NODES ]"
    shell: ps -ef | grep java | grep -v grep | grep /app/skyfall/java/ | awk '{print $2}' | wc -l
    changed_when: false
    register: skyfall__process
  -
    debug: var=skyfall__process.stdout_lines

  -
    name: "STOP SKYFALL APPLICATION [ ALL NODES ]"
    shell: echo "sh /app/skyfall/applicationScript.sh APPLICATION_STOP"
    register: application__status
    when: skyfall__process.stdout|int == 0
  -
    debug: var=application__status.stdout_lines

