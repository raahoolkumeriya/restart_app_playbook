- 
  gather_facts: false
  hosts: localhost #primary_host,secondary_host,tertiary_host,quaternary_host
  remote_user: root

  tasks:
  -
    name: "SCHEDULER PROCESS"
    shell: ps -ef | grep -v grep | grep autosys | awk '{print $2}' | wc -l
    # ^^ Modify process with correct schedular name eg. autosys, controlm etc 
    changed_when: false 
    register: scheduler__process
  - 
    debug: var=scheduler__process.stdout_lines

  -
    name: "SCHEDULER STOP"
    shell: echo "/app/snakebite/restart-shdlr/stop" 
    register: shdlr__status
    when: scheduler__process.stdout|int != 0
  - 
    debug: var=shdlr__status.stdout_lines
