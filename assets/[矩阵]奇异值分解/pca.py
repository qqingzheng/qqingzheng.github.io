from PIL import Image
import numpy as np

image = Image.open("/Users/rikka/Desktop/SCR-20250724-mfro.png").convert("L")

# Resize到方阵
image = image.resize((128, 128))
image.save("image_resized.png")

image_array = np.array(image)

eigenvalues, eigenvectors = np.linalg.eig(image_array)

D = np.diag(eigenvalues)
P = eigenvectors
D[-96:, -96:] = 0

reconstructed_image = P @ D @ np.linalg.inv(P)

reconstructed_image = np.real(reconstructed_image).astype(np.uint8)
reconstructed_image = Image.fromarray(reconstructed_image)
reconstructed_image.save("reconstructed_image.png")
