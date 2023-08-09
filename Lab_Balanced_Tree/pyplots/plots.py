import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Tempo de busca
# STL
def log_func(n, k, c):
    return k * np.log(n) + c

data = pd.read_csv('./oak_search.csv')

x = data.iloc[:, 1]
y = data.iloc[:, 2]

popt, pcov = curve_fit(log_func, x, y)

k = popt[0]
c = popt[1]

plt.figure(figsize=(10 ,8))
plt.scatter(x, y, s = 20, facecolors = 'none', edgecolors='blue', color = 'blue')
plt.plot(x, log_func(x, k, c), color = 'black')
print(f'{k}*log(n) + {c}')
plt.xlabel('Quantidade de elementos inseridos')
plt.ylabel('Tempo de busca médio (µs)')
plt.title('Tempo de busca STL')
plt.savefig('buscaSTL.png', dpi=400, pad_inches=0)

# Aluno
y = data.iloc[:, 3]

popt, pcov = curve_fit(log_func, x, y)
k = popt[0]
c = popt[1]

plt.figure(figsize=(10 ,8))
plt.scatter(x, y, s = 20, facecolors = 'none', edgecolors='red', color = 'red')
plt.plot(x, log_func(x, k, c), color = 'black')
print(f'{k}*log(n) + {c}')
plt.xlabel('Quantidade de elementos inseridos')
plt.ylabel('Tempo de busca médio (µs)')
plt.title('Tempo de busca Aluno')
plt.savefig('buscaALU.png', dpi=400, pad_inches=0)


# Tempo de inserção
# STL
y = data.iloc[:, 4]

popt, pcov = curve_fit(log_func, x, y)

k = popt[0]
c = popt[1]

plt.figure(figsize=(10 ,8))
plt.scatter(x, y, s = 20, facecolors = 'none', edgecolors='blue', color = 'blue')
plt.plot(x, log_func(x, k, c), color = 'black')
print(f'{k}*log(n) + {c}')
plt.xlabel('Quantidade de elementos inseridos')
plt.ylabel('Tempo de inserção médio (µs)')
plt.title('Tempo de inserção STL')
plt.savefig('insertSTL.png', dpi=400, pad_inches=0)

# Aluno
y = data.iloc[:, 5]

popt, pcov = curve_fit(log_func, x, y)

k = popt[0]
c = popt[1]

plt.figure(figsize=(10 ,8))
plt.scatter(x, y, s = 20, facecolors = 'none', edgecolors='red', color = 'blue')
plt.plot(x, log_func(x, k, c), color = 'black')
print(f'{k}*log(n) + {c}')
plt.xlabel('Quantidade de elementos inseridos')
plt.ylabel('Tempo de inserção médio (µs)')
plt.title('Tempo de inserção Aluno')
plt.savefig('insertALU.png', dpi=400, pad_inches=0)