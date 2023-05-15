import heapq

class TreeNode:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''
     # less 
    def __lt__(self, nxt):
        return self.freq < nxt.freq
    
    
class HuffmanCoding:
    def __init__(self, letters, freqs):
        self.letters = letters
        self.freqs = freqs
        self.encode_seqs = {}
        self.decode_seqs = {}
        self.__build_tree()
    def printNodes(self, node, val=''):
        newVal = val + str(node.huff)
        if(node.left):
            self.printNodes(node.left, newVal)
        if(node.right):
            self.printNodes(node.right, newVal)
        if(not node.left and not node.right):
            self.encode_seqs[node.symbol] = newVal
            self.decode_seqs[newVal] = node.symbol
            print(f"{node.symbol} : {newVal}")
    
    def printTree(self, node, level=0):
        if node is not None:
            self.printTree(node.right, level+1)
            print(' ' * 12 * level + '->', node.huff, node.symbol)
            self.printTree(node.left, level+1)

 
    def __build_tree(self):
        self.nodes = []
        for x in range(len(self.letters)):
            heapq.heappush(self.nodes, TreeNode(self.freqs[x], self.letters[x]))
        while len(self.nodes) > 1:
            left = heapq.heappop(self.nodes)
            right = heapq.heappop(self.nodes)
            left.huff = "0"
            right.huff = "1"
            newNode = TreeNode(left.freq + right.freq, left.symbol + right.symbol, left, right)
            heapq.heappush(self.nodes, newNode)
        self.printNodes(self.nodes[0])
        self.printTree(self.nodes[0])
    def encode(self, word):
        res = ""
        for char in word:
            if char == ' ':
                res += " "
                continue
            res += self.encode_seqs[char]
        return res
    def decode(self, encoded_word):
        res = ""
        while len(encoded_word) > 0:
            for seq, letter in self.decode_seqs.items():
                index = encoded_word.find(seq)

                if index == 0:
                    res += letter
                    encoded_word = encoded_word[:index] + encoded_word[index+len(seq):]
                    break
        return res
    
freqs = [25, 13, 13, 27, 27, 9, 29, 15, 30, 6]
letters = ['а', 'о', 'у', 'б', 'в', 'д', 'м', 'н', 'р', 'т']
print(freqs)
print(letters)

codes = HuffmanCoding(letters, freqs)


print(codes.encode("добробут дома"))

print(codes.decode("010111001001101100111110110"))
        