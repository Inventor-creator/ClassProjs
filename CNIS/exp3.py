def vigenere_cipher(text, key, mode='encrypt'):
    result = []
    key = key.upper()
    key_index = 0

    for char in text:
        if char.isalpha():

            shift = ord(key[key_index % len(key)]) - ord('A')
            if mode == 'decrypt':
                shift = -shift

            start = ord('A') if char.isupper() else ord('a')
            new_char = chr((ord(char) - start + shift) % 26 + start)
            result.append(new_char)

            key_index += 1
        else:

            result.append(char)

    return "".join(result)


message = str(input("enter message: "))
secret_key = "thisismysecretkey"

encrypted = vigenere_cipher(message, secret_key, mode='encrypt')
decrypted = vigenere_cipher(encrypted, secret_key, mode='decrypt')

print(f"original:  {message}")
print(f"encrypted: {encrypted}")
print(f"decrypted: {decrypted}")
