def clean_log_message(log_message):
    log_message = log_message.lower()

    clean_message = " "

    for ch in log_message:
        if ch.isalnum() or ch == " ":
            clean_message += ch

    cleaned = " ".join(clean_message.split())

    print("\n original \n", log_message)
    print("\n cleaned \n", cleaned)


log_message = "Disk Error on /dev/shell"
clean_log_message(log_message)