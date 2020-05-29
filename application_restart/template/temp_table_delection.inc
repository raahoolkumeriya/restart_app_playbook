-
  gather_facts: false
  hosts: localhost #primary_host
  remote_user: root

  tasks:
  -
    name: "DELETING TEMP TABLES"
    shell: echo "sh /app/skyfall/tempDelection.sh"
    changed_when: false
    register: deleting__temp__tables
  -
    debug: var=deleting__temp__tables.stdout_lines
