# Custom build of Kernel from Linux kernel source trees:

Passos para gerar um build costumizado do kernel do linux a partir do Linux kernel source trees:

OBS: Realize esse teste preferencialmente dentro de uma VM.

Pré-requisitos: 
<pre>
sudo apt install gcc
sudo apt install linux-headers-generic
sudo apt install git fakeroot build-essential tar ncurses-dev
tar xz-utils libssl-dev bc stress python3-distutils libelf-dev
linux-headers-$(uname -r) bison flex libncurses5-dev util-
linux net-tools linux-tools-$(uname -r) exuberant-ctags cscope
sysfsutils gnome-system-monitor curl perf-tools-unstable
gnuplot rt-tests indent tree pstree smem libnuma-dev numactl
hwloc bpfcc-tools sparse flawfinder cppcheck tuna hexdump
openjdk-14-jre trace-cmd virt-what
</pre>

Faça o clone da mainline Linux Git repository (Torvalds' Git tree):
<pre>
git clone --depth=3 https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
</pre>
Para gerar um ponto de partida de configuração para o custom kernel abordagem a partir do localmodconfig:
<pre>
lsmod > /tmp/lsmod.now

cd /Raiz_da_Pasta_Clonada

make LSMOD=/tmp/lsmod.now localmodconfig

make menuconfig
</pre>
ATENÇÃO: Realize com cautela as modificações desejadas no kernel via menu de configurações.

Por exemplo, modifique o número da versão do kernel a ser gerada da seguinte forma: 

Opção: General Setup / Local version - append to kernel release

CONFIG_LOCALVERSION 

none para -llkd01

Após salvar e sair do menu de configurações execute:

<pre>
time make -j4 
sudo make modules_install
sudo make install
</pre>

Reinicie o linux, e no menu GRUB selecione o novo kernel para realização do boot. 