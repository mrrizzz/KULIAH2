#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char typeInfo;
typedef struct Node tree;
struct Node
{
  typeInfo info;
  tree *kiri;
  tree *kanan;
};

tree *bentuk(typeInfo info);
void sisip(tree **root, typeInfo info);
void preorder(tree *root);
void postorder(tree *root);
void inorder(tree *root);
void menu_kunjungan(tree **root);
tree *cari(tree *root, typeInfo info);

int main()
{
  tree *root = NULL;
  typeInfo data;
  char lain;
  char input[100];

  printf("MEMBENTUK SEBUAH TREE\n");
  printf("Ketikkan data/infonya (pisahkan dengan spasi): ");
  fgets(input, sizeof(input), stdin);

  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n')
    input[len - 1] = '\0';
  char *token = strtok(input, " ");
  while (token != NULL)
  {
    sisip(&root, token[0]);
    token = strtok(NULL, " ");
  }

  do
  {
    menu_kunjungan(&root);
    getchar();
    printf("Mau coba metode lain ?  ");
    scanf("%c", &lain);
  } while (lain == 'y' || lain == 'Y');

  do
  {
    printf("Mencari data dalam tree ... \n");
    printf("Masukkan data yang ingin dicari: ");
    scanf(" %c", &data);
    tree *hasilCari = cari(root, data);
    printf("Data '%c' %sditemukan dalam tree\n", data, hasilCari != NULL ? "" : "tidak ");
    getchar();
    printf("Mau coba cari data lain ?  ");
    scanf("%c", &lain);
  } while (lain == 'y' || lain == 'Y');

  return 0;
}
tree *bentuk(typeInfo info)
{
  tree *node_baru = (tree *)malloc(sizeof(tree));
  if (node_baru != NULL)
  {
    node_baru->info = info;
    node_baru->kiri = NULL;
    node_baru->kanan = NULL;
  }
  return node_baru;
}

void sisip(tree **root, typeInfo info)
{
  tree *node_baru = bentuk(info);
  if (*root == NULL)
  {
    *root = node_baru;
    return;
  }

  tree *p = *root;
  tree *q = *root;

  while (q != NULL && node_baru->info != p->info)
  {
    p = q;
    if (info < p->info)
      q = p->kiri;
    else
      q = p->kanan;
  }

  if (info == p->info)
  {
    printf("Duplikasi data : %c\n", info);
    free(node_baru);
    return;
  }

  if (node_baru->info < p->info)
    p->kiri = node_baru;
  else
    p->kanan = node_baru;
}

void preorder(tree *root)
{
  if (root != NULL)
  {
    printf("%c ", root->info);
    preorder(root->kiri);
    preorder(root->kanan);
  }
}

void postorder(tree *root)
{
  if (root != NULL)
  {
    postorder(root->kiri);
    postorder(root->kanan);
    printf("%c ", root->info);
  }
}

void inorder(tree *root)
{
  if (root != NULL)
  {
    inorder(root->kiri);
    printf("%c ", root->info);
    inorder(root->kanan);
  }
}

void menu_kunjungan(tree **root)
{
  int pilihan;
  printf("Pilih Penelusuran Tree\n");
  printf("1. Preorder\n");
  printf("2. PostOrder\n");
  printf("3. Inorder\n");
  printf("Pilihan anda: ");
  scanf("%d", &pilihan);

  printf("Hasil penelusuran menggunakan ");
  switch (pilihan)
  {
  case 1:
    printf("Preorder:\n");
    preorder(*root);
    break;
  case 2:
    printf("PostOrder:\n");
    postorder(*root);
    break;
  case 3:
    printf("Inorder:\n");
    inorder(*root);
    break;
  default:
    printf("Pilihan tidak valid.\n");
    break;
  }
  printf("\n");
}

tree *cari(tree *root, typeInfo info)
{
  while (root != NULL && root->info != info)
  {
    if (info < root->info)
    {
      root = root->kiri;
    }
    else
    {
      root = root->kanan;
    }
  }
  return root;
}
