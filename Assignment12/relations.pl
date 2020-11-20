% Ankit Das - 15th November - Relations


father(devang,kyra).   % devang is the father of kyra
father(rajat,nikita).  % rajat is the father of nikita
father(alex,devang).   % alex is the father of devang
father(devang,shreya). % devang is the father of shreya
mother(gita,devang).   % gita is the mother of devang => alex is married to gita
mother(nikita,kyra).   % nikita is the mother of kyra => nikita is married to devang 
mother(diya,nikita).   % diya is the mother of nikita => diya is married to rajat
mother(nikita,shreya). % nikita is the mother of shreya => shreya and kyra are siblings => gita, alex and rajat, diya are Grandparents of kyra and shreya  

female(kyra).
female(nikita).
female(diya).
female(gita).
female(shreya).
male(rajat).
male(devang).
male(alex).

parent(X,Y):-father(X,Y);mother(X,Y).
married(X,Y):-male(X),female(Y),children(M,X),children(M,Y).
grandparent(X,Y):-parent(X,M),parent(M,Y).
fgrandfather(X,Y):-father(X,K),father(K,Y).
mgrandfather(X,Y):-father(X,K),mother(K,Y).
mgrandmother(X,Y):-mother(X,K),mother(K,Y).
fgrandmother(X,Y):-mother(X,K),father(K,Y).
children(X,Y):-parent(Y,X).
son(X,Y):-children(X,Y),male(X).
daughter(X,Y):-children(X,Y),female(X).
sibling(X,Y):-mother(M,X),mother(M,Y),father(F,X),father(F,Y),X=Y.
