def majority(x, y, z):
    return (x & y) | (x & z) | (y & z)


def xor_bits(bits):
    result = 0
    for b in bits:
        result ^= b
    return result


def shift_register(register, taps):
    feedback = xor_bits([register[t] for t in taps])
    register.pop()
    register.insert(0, feedback)


def generate_keystream(key, length):

    R1 = [int(b) for b in key[:19]]
    R2 = [int(b) for b in key[19:41]]
    R3 = [int(b) for b in key[41:64]]

    keystream = []

    for _ in range(length):
        m = majority(R1[8], R2[10], R3[10])

        if R1[8] == m:
            shift_register(R1, [13, 16, 17, 18])
        if R2[10] == m:
            shift_register(R2, [20, 21])
        if R3[10] == m:
            shift_register(R3, [7, 20, 21, 22])

        ks_bit = R1[18] ^ R2[21] ^ R3[22]
        keystream.append(ks_bit)

    return keystream


def text_to_bits(text):
    bits = []
    for char in text:
        binary = format(ord(char), '08b')
        bits.extend([int(b) for b in binary])
    return bits


def bits_to_text(bits):
    chars = []
    for i in range(0, len(bits), 8):
        byte = bits[i:i+8]
        byte_str = ''.join(str(b) for b in byte)
        chars.append(chr(int(byte_str, 2)))
    return ''.join(chars)


def a51_encrypt():
    key = input("Enter 64-bit binary key: ")

    if len(key) != 64 or not all(c in '01' for c in key):
        print("Key must be exactly 64 bits (0s and 1s).")
        return

    plaintext = input("Enter plaintext: ")

    data_bits = text_to_bits(plaintext)
    keystream = generate_keystream(key, len(data_bits))

    cipher_bits = [data_bits[i] ^ keystream[i] for i in range(len(data_bits))]

    cipher_binary = ''.join(str(b) for b in cipher_bits)

    print("Ciphertext (binary):", cipher_binary)


def a51_decrypt():
    key = input("Enter 64-bit binary key: ")

    if len(key) != 64 or not all(c in '01' for c in key):
        print("Key must be exactly 64 bits (0s and 1s).")
        return

    cipher_binary = input("Enter ciphertext (binary): ")

    cipher_bits = [int(b) for b in cipher_binary]
    keystream = generate_keystream(key, len(cipher_bits))

    plain_bits = [cipher_bits[i] ^ keystream[i] for i in range(len(cipher_bits))]

    plaintext = bits_to_text(plain_bits)

    print("Decrypted text:", plaintext)



while True:
    print("\nA5/1 Algorithm")
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Exit")

    choice = input("Enter choice: ")

    if choice == '1':
        a51_encrypt()
    elif choice == '2':
        a51_decrypt()
    elif choice == '3':
        break
    else:
        print("Invalid choice.")
