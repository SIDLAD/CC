VOCAB_SZ = 28

def char_to_idx(char: str) -> int:
    """Maps a character to an index."""
    if char == '$':
        return VOCAB_SZ - 2  # START CHARACTER
    if char == '#':
        return VOCAB_SZ - 1  # END CHARACTER
    return ord(char) - ord('a')

def idx_to_char(idx: int) -> str:
    """Maps an index to a character."""
    if idx == VOCAB_SZ - 2:
        return '$'
    if idx == VOCAB_SZ - 1:
        return '#'
    return chr(idx + ord('a'))



print(char_to_idx('_'))