try:
    f = open('BinaryFile.txt', 'rb')
    
    string_data = f.decode('utf-8', errors='replace')
    f.close()  
except FileNotFoundError:
        print(f"Error: The file 'BinaryFile.txt' does not exist.")
except Exception as e:
        print(f"An error occurred: {e}")
