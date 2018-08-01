exclui([X,_Y,_Z,_W],[X]).
exclui([X|Cauda],[X|Cauda1]):-exclui(Cauda,Cauda1).

exclui_inicio([_X,_Y,_Z|Cauda],Cauda).

conc([],L,L).
conc([X|L1],L2,[X|L]) :-conc(L1,L2,L).

ultimo(X,[X]).
ultimo(X,[_Y|L]):-ultimo(X,L).

par(N):- N mod 2 =:= 0.
impar(N):- N mod 2 =:= 1.

tamanho([],0).
tamanho([_|Cauda],N):-
	tamanho(Cauda,N1),
	N is 1+N1.

tamanhopar(L,N):- tamanho(L,N),
                  par(N).

tamanhoimpar(L,N):- tamanho(L,N),
                    impar(N).

f([X,_A],X).
f([_|T],L):-f(T,L).

soma([],0).
soma([X|L],Soma):-soma(L,LS),
	Soma is X+LS.

somatorio(Lista,Soma):-soma(Lista,Soma).

insere(X,[],[X]).
insere(X,[Y|L1],[Y|L2]):-insere(X,L1,L2).

insereOrdenado([],[],[]).
insereOrdenado(X,[],[X]).
insereOrdenado(X,[Y|L1],[X,Y|L1]):-X<Y,!.
insereOrdenado(X,[Y|L1],[Y|L2]):-insereOrdenado(X,L1,L2).

inverter([],[]).
inverter([X|Y],L):-inverter(Y,Lista),
	           conc(Lista,[X],L).

palindromo(X):- inverter(X,L),
	        X==L.

roda([],[]).
roda([X|L],L2):-conc(L,[X],L2).
