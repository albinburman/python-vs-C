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

while True:
    print("\n═══ NÄTVERKSVERKTYG (Python) ═══")
    print("1. Validera IP-adress")
    print("2. Validera port")
    print("3. Visa logg")
    print("4. Avsluta")

    choice = input("Välj ett alternativ: ")

    if choice == "1":
        ip = input("Ange IP-adress: ")

        if validate_ip(ip):
            print(f"{ip} är en giltig IP-adress.")
            logg.append(f"IP {ip} - giltig")
        else:
            print(f"{ip} är inte en giltig IP-adress.")
            logg.append(f"IP {ip} - ogiltig")

    elif choice == "2":
        try:
            port = int(input("Ange port: "))
            if validate_port(port):
                print(f"{port} är en giltig port.")
                logg.append(f"Port {port} - giltig")
            else:
                print(f"{port} är inte en giltig port.")
                logg.append(f"Port {port} - ogiltig")
        except ValueError:
            print("Du måste skriva ett heltal.")
            logg.append("Port ??? - ogiltig (fel input)")

    elif choice == "3":
        print("\n═══ LOGG ═══")
        if not logg:
            print("Inga valideringar gjorda ännu.")
        else:
            for i, entry in enumerate(logg, start=1):
                print(f"{i}. {entry}")

    elif choice == "4":
        print("Avslutar programmet...")
        break

    else:
        print("Ogiltigt val.")

