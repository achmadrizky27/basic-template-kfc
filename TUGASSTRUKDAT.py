#DOUBLY LINKED LIST
#=======================================================================
 
import os
 
# Class Node
class Node(object):
    # Inisialisasi node
    def __init__(self, data, prev, next):
        self.data = data
        self.prev = prev
        self.next = next
 
# Class untuk linked list
class DoubleList(object):
 
    head = None
    tail = None        
    # Menambah node
    def menuTambah(self):
        os.system('clear')
        temp = int(input('Masukkan data baru = '))
        new_node = Node(temp, None, None)
        # Memeriksa apakah list kosong
        if self.head is None:
            # Menunjuk HEAD dan TAIL ke node baru
            self.head = self.tail = new_node
        # Ketika list tidak kosong
        else:
            new_node.prev = self.tail
            new_node.next = None
            self.tail.next = new_node
            self.tail = new_node
   
    # Menghapus node
    def menuHapus(self):
        os.system('clear')
        temp = int(input('Masukkan data yang akan dihapus = '))
        # Membuat pointer yang menunjuk ke node pertama
        current_node = self.head
       
        # Melakukan perulangan saat list tidak kosong
        while current_node is not None:
            # Memeriksa data pada node yang ditunjuk pointer merupakan node yang akan dihapus
            if current_node.data == temp:
                #jika node yang dicari berada pada elemen terakhir
                if current_node.next is None:
                    current_node.prev.next = None
                # jika node yang dicari berada bukan pada elemen pertama
                elif current_node.prev is not None:
                    current_node.prev.next = current_node.next
                    current_node.next.prev = current_node.prev
                # Jika node yang dicari berada pada elemen pertama
                else:
                    self.head = current_node.next #memindahkan head ke elemen berikutnya
                    current_node.next.prev = None #menunjuk head prev menjadi none
 
            # Memindahkan pointer menunjuk ke node berikutnya
            current_node = current_node.next
           
    # Menampilkan isi dari list    
    def menuTampil(self):
        os.system('clear')
        print ("Tampilkan list data:")
       
        # Membuat pointer yang menunjuk ke node pertama
        current_node = self.head
        # Perulangan menampilkan data beserta data sebelum dan sesudahnya
        while current_node is not None:
            print (current_node.prev.data) if hasattr(current_node.prev, "data") else None,
            print (current_node.data),
            print (current_node.next.data) if hasattr(current_node.next, "data") else None
            # Menunjuk ke node berikutnya
            current_node = current_node.next
           
    # Menampilkan menu program     
    def menuUmum(self):
        pilih = "y"
        while ((pilih == "y") or (pilih == "Y")):
            os.system('clear')
            print('Pilih menu yang anda inginkan')
            print('==============================')
            print('1 : Tambah data ke linked list')
            print('2 : Hapus data di linked list')
            print('3 : Tampilkan data di linked list')
            print('4 : Keluar Program')
            pilihan = str(input("Masukkan Menu yang anda pilih = "))
            if(pilihan == "1"):
                self.menuTambah()
            elif(pilihan == "2"):
                self.menuHapus()
            elif(pilihan == "3"):
                self.menuTampil()
                x = input("")
            else :
                pilih ="n"
               
if __name__ == "__main__":
    # execute only if run as a script
    d = DoubleList()
    d.menuUmum()