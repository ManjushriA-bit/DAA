def rabin_karp(text, pattern):
    d = 256
    q = 101
    m = len(pattern)
    n = len(text)
    p = 0
    t = 0
    h = 1

    # Calculate h = d^(m-1) % q
    for i in range(m - 1):
        h = (h * d) % q

    # Initial hash values
    for i in range(m):
        p = (d * p + ord(pattern[i])) % q
        t = (d * t + ord(text[i])) % q

    # Slide the pattern over text
    for i in range(n - m + 1):
        if p == t:
            if text[i:i + m] == pattern:
                print("Pattern found at index", i)

        if i < n - m:
            t = (d * (t - ord(text[i]) * h) + ord(text[i + m])) % q
            if t < 0:
                t += q


text = "GEEKS FOR GEEKS"
pattern = "FOR"
rabin_karp(text, pattern)
