logg = []

def validate_ip(ip):
    delar = ip.split(".")
    if len(delar) != 4:
        return False

    for del_ in delar:
        if not del_.isdigit():
            return False
        num = int(del_)
        if num < 0 or num > 255:
            return False

    return True

def validate_port(port):
    return 1 <= port <= 65535



