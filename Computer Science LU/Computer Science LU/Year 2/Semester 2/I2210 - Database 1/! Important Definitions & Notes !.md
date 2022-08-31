# Keys
- `Super Key`
	K is a super key for relation schema R if and only if K->R _(K determines all attributes of R)_ ^superKey
- `Candidate Key`
	K is a candidate key for R if and only if K->R and there is no `a`  belongs to K such that `a` -> R _(make sure the key is the shortest possible)_ ^candidateKey
- `Minimal Key`
	Any attribute which does not appear in the right member of a non trivial [[1 @ Normaliztion Process#Functional Dependencies|FD]] of F must be a key (candidate or minimal) of R
