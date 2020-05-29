-
  gather_facts: false
  hosts: localhost #primary_host,secondary_host,tertiary_host,quaternary_host
  remote_user: root

  tasks:
  - name: "Message: 'LOG_MESSAGE' in server logs [ALL NODES]"
    shell: echo "fgrep -i 'LOG_MESSAGE' /app/snakebite/jboss/logs/application_Server.log"
    register: log__status
    until: log__status.stdout.find(log_message) != -1
    delay: 1
    retries: 3
    ignore_errors: true
  - debug: var=log__status.stdout_lines

