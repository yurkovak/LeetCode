# O(N)
class Solution(object):
    def getHint(self, secret, guess):
        secret_map = [0]*10
        for i in range(len(secret)):
            secret_map[int(secret[i])] += 1
        
        bulls, cows = 0, 0
        for i in range(len(guess)):
            g, s = guess[i], secret[i]
            if g == s and secret_map[int(g)] > 0:
                bulls += 1
                secret_map[int(g)] -= 1
        
        for i in range(len(guess)):
            g, s = guess[i], secret[i]
            if g != s and secret_map[int(g)] > 0:
                cows += 1
                secret_map[int(g)] -= 1
        
        return str(bulls) + 'A' + str(cows) + 'B'


if __name__ == '__main__':
    secret = input('secret: ')
    guess = input('guess: ')
    print('Hint: ', Solution().getHint(secret, guess))