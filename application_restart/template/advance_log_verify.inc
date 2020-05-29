---
  -
    gather_facts: false
    hosts: localhost #primary_host,secondary_host,tertiary_host,quaternary_host
    remote_user: root
    tasks:
    - 
      name: ADVANCE LOG CHECKS - I 
      shell: echo "fgrep -i log_message /app/snakebite/jboss/logs/application_Server.log"
      changed_when: false
      register: advance__checks__1
      ignore_errors:  true
    -
      debug: 
          msg: "MESSAGE FOUND IN LOGS"
      when: advance__checks__1.rc == 0

    -
      debug:
          msg: "MESSAGE NOT FOUND IN LOGS"
      when: advance__checks__1.rc != 0 

    -
      name: "ADVANCE HEALTH CHECKS - II [ ALL NODES ]"
      shell: echo "fgrep -i log_message /app/snakebite/jboss/logs/application_Server.log"
      changed_when: false
      register: advance__checks__2
      ignore_errors:  true
    -
      debug:
          msg: "MESSAGE FOUND IN LOGS"
      when: advance__checks__2.rc == 0

    -
      debug:
          msg: "MESSAGE NOT FOUND IN LOGS"
      when: advance__checks__2.rc != 0
  
