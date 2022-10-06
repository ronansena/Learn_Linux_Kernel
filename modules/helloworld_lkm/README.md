<h1> Compilar, carregar e remover um kernel módulo da memória do Linux</h1>

Arquivos necessários:

<pre>
helloworld_lkm.c
Makefile
</pre>

Executar comando para compilar o programa arquivo helloworld_lkm.c:

<pre>
make clean && make
</pre>

Para carregar o módulo na memória, execute: 

<pre>
sudo insmod helloworld_lkm
</pre>

Para verificar se o módulo foi carregado, execute: 

<pre>
lsmod | head
sudo dmesg -c > /dev/null
</pre>

Para remover o módulo da memória, execute: 

<pre>
sudo insmod helloworld_lkm
</pre>





