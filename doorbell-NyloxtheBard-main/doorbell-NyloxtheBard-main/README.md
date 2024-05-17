# Doorbell

## Experience Summary

### How many hours did it take to complete assignment?
2 hours

### What did you enjoy about this lab?
It is finished. I enjoyed having a working doorbell that fully functions. 

### What were the major challenges you had with this lab? Try to be as detailed as possible.
The only major issue I had was when my rasberry got stuck because I didn't read the message about adding a 15 second timer into my main function until after I was running the program. That instruction should be moved up before all of the setup to run automatically upon powering on, as that was a bit of a headache. 

## Lab Specific Tasks

### systemd Daemons
1. What is a daemon?

Daemon is an auto start program that is not directly started by the user, and happens once the device powers on. 

2. What is `systemd`?

systemd is a service/system manager that starts immediately upon device boot. It is responsible for handling processes, including stopping and starting them, especially when concerning managing the boot process.

3. What program controls `systemd` daemons?

'systemctl'

4. What kind of file is made to create a daemon in `systemd`?

A service file

5. Explain the difference between systemctl start and systemctl enable. When would you use one over the other?

'systemctl' start allows for the daemon to be started by manual user input, while enable will start the program automatically upon boot without user input. Using 'systemctl' start is more useful when the user needs more control over the program being run, while enable is useful if it is an automated service that the user could potentially mess up or with if they had access to the entire program. 

6. Can you think of another real-world application where you might want a program to start automatically on boot? Describe the scenario.

For the majority of computer users, having the OS system start automatically on boot is the preferred method, as it otherwise would be an extremely tedious process to get the OS program running otherwise. It is something that we often take for granted since it just automatically starts, but without that auto startup upon boot, it would be extremely hard to get that working otherwise, which is why it is set up this way instead. 

7. Do a little research on your own and list 3 different daemons that run by default in Linux. Why are those programs better as daemons than normal programs?

cron - manages scheduled tasks, allows for them to be run at periodic intervals

sshd - provides the SSH daemon for secured remote access

cups - manages printing tasks

These are better as daemons than normal programs, as they start upon system boot and don't even need a user to be logged in, which is important for cron as it can handle updates and other procedures for the computer even without a user logged in or using the device. They also tend to be more efficient, as they can optimize resources when the device is idle, and only work when the system is being used. Another key reason these tend to work better as daemons than normal programs is both the consistency and autonomous they offer, as the user doesn't have to think about these programs ever, which for these ones particularly is better this way, as it would be more tedious otherwise to continously start and stop them instead of just leaving them running idly in the background and start up with the device boot. 
