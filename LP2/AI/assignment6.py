def ask(question: str) -> bool:
    return input(question + " (y/n): ").lower().strip().startswith("y")


def diagnose_power_issue() -> bool:
    return ask("Is the computer not turning on?") and ask("Is the power cable connected properly?")


def diagnose_display_issue() -> bool:
    return ask("Is the monitor screen blank?") and ask("Do you hear beeps or fan noise?")


def diagnose_overheating() -> bool:
    return ask("Is your computer unusually hot?") and ask("Does it shut down randomly?")


def diagnose_slow_computer() -> bool:
    return ask("Is your computer running slow?") and ask("Do you have many applications running?")

def diagnose_internet_issue() -> bool:
    return ask("Are you unable to browse the internet?") and ask("Is your Wi-Fi or LAN connected?")


def diagnose_software_crash() -> bool:
    return ask("Are applications closing unexpectedly?") and ask("Do you see error messages?")


print("🔧 Expert System for Diagnosing Computer Issues")

if diagnose_power_issue():
    print("💡 Suggestion: Check the power cable or try another outlet.")
if diagnose_display_issue():
    print("💡 Suggestion: Check the monitor connection or test with another monitor.")
if diagnose_overheating():
    print("💡 Suggestion: Clean internal fans or ensure proper ventilation.")
if diagnose_slow_computer():
    print("💡 Suggestion: Close unused apps or check for viruses.")
if diagnose_internet_issue():
    print("💡 Suggestion: Restart your router or check network settings.")
if diagnose_software_crash():
    print("💡 Suggestion: Reinstall the app or check for software updates.")
