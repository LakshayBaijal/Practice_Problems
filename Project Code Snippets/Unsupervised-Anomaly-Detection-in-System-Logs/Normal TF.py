def term_frequence(message):
    freq = {}

    for msg in message:
        words = msg.split()

        for word in words:
            if word in freq:
                freq[word] += 1
            else:
                freq[word] = 1
    print("Word Frequence \n")
    for word,count in freq.items():
        print(word,count,"\n")




message = [
    "disk error full",
    "disk full occurred"
]

term_frequence(message)