---
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
      name: "ADAPTER STOP"
      shell: echo "sh /app/snakebite/adapter.sh STOP"
      register: adapter__status
      when: adapter__process.stdout|int == 0  # should be 1 is its running  
    -
      debug: var=spectre__status.stdout_lines