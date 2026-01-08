
def severity(low_log_line):
    if "error" in low_log_line:
        severity = "Error"
    elif "warn" in low_log_line:
        severity = "Warning"
    else:
        severity = "Info"

    print(severity)



log_line = "12 Jan 20:20:20 Error Message1 Message2"
low_log_line = log_line.lower()

severity(low_log_line)