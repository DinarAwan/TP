from selenium import webdriver
from selenium.webdriver.common.by import By
import pyautogui
import keyboard
import time
import random

driver = webdriver.Chrome()
driver.get("https://10fastfingers.com/typing-test/indonesian")
time.sleep(3)

def klik_input_field():
    print("🖱️ Arahkan dan klik kolom input...")
    time.sleep(3)
    x, y = pyautogui.position()
    pyautogui.click(x, y)

def start_typing():
    for key in 'abcdefghijklmnopqrstuvwxyz0123456789 .,/[]=-;':
        keyboard.block_key(key)

    wrong_indices = random.sample(range(10, 90), 4)
    typed_count = 1
    print(f"❌ Akan bikin salah di kata ke: {wrong_indices}")

    while True:
        try:
            timer = driver.find_element(By.ID, "timer").text
            if timer == "0:00":
                print("✅ Waktu habis. Silakan refresh halaman dari browser.")
                break

            word = driver.find_element(By.CSS_SELECTOR, "#row1 .highlight").text
            if not word:
                continue

            if typed_count in wrong_indices:
                typo_word = word[:-1] + 'x' if len(word) > 1 else word + 'x'
                print(f"[{typed_count}] ❌ SALAH: {typo_word}")
                pyautogui.typewrite(typo_word, interval=random.uniform(0.06, 0.12))
            else:
                print(f"[{typed_count}] ✅ BENAR: {word}")
                pyautogui.typewrite(word, interval=random.uniform(0.07, 0.12))

            pyautogui.press('space')
            typed_count += 1
            time.sleep(random.uniform(0.08, 0.12))

        except Exception as e:
            print("❌ Error:", e)
            break

    for key in 'abcdefghijklmnopqrstuvwxyz0123456789 .,/[]=-;':
        keyboard.unblock_key(key)

# === LOOP: tunggu refresh baru lanjut ===
klik_input_field()

while True:
    start_typing()

    # Tunggu kamu refresh browser secara manual
    print("⏳ Menunggu kamu refresh halaman dari browser...")

    # Tunggu sampai elemen pertama muncul lagi
    while True:
        try:
            highlight = driver.find_element(By.CSS_SELECTOR, "#row1 .highlight")
            if highlight.is_displayed():
                print("🔄 Halaman ter-refresh. Mulai lagi...")
                time.sleep(1)
                break
        except:
            pass
        time.sleep(1)
