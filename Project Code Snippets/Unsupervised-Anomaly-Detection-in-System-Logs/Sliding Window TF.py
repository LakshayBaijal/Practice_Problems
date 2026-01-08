
def ngram_function(message):
    window_size = 3
    tf = {}

    for i in range(0,len(message),window_size):
        ngram = message[i:i+window_size]

        if ngram in tf:
           tf[ngram] += 1
        else:
            tf[ngram] = 1

    print("Character Ngram")
    for word,count in tf.items():
        print(word,count) 





message = "/user/bin/sshd"
ngram_function(message)




