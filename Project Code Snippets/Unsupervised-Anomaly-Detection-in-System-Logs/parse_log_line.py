
def log_parse(low_log_line):

    parts = low_log_line.split()

    Timestamp = parts[0] + " " + parts[1] + " " + parts[2]

    Severity = parts[3]

    message = " ".join(parts[4:])

    parse_log = { 
        "Timestamp" : Timestamp,
        "Severity" : Severity,
        "Message" : message
    }

    print(parse_log)

log_line = "12 Jan 20:20:20 Error Message1 Message2"
low_log_line = log_line.lower()
log_parse(low_log_line)