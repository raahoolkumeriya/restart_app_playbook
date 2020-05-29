- 
  gather_facts: false
  hosts: localhost #primary_host,secondary_host,tertiary_host,quaternary_host
  remote_user: root 

  tasks:
  -
    name: "ADAPTER STATUS"
    shell: ps -ef | grep -v grep | grep adapter | awk '{print $2}' | wc -l
    changed_when: false 
    register: adapter__process
  - 
    debug: var=adapter__process.stdout_lines

  -
    name: "ADAPTER START"
    shell: echo "sh /app/snakebite/adapter.sh RESTART"
    register: adapter__status
    when: adapter__status.stdout|int == 0 
  -
    debug: var=spectre__status.stdout_lines

