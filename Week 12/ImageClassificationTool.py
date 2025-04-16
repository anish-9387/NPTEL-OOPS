from PIL import Image
import numpy as np

from tensorflow.keras.applications import MobileNet # type: ignore
from tensorflow.keras.applications.mobilenet import preprocess_input # type: ignore

from tensorflow.keras.applications.mobilenet import decode_predictions # type: ignore

class ImageLoader:
    def __init__(self, image_path):
        self.image_path=image_path

    def load_image(self):
        try:
            image=Image.open(self.image_path)
            image=image.convert("RGB")  # Convert to RGB to ensure 3 channels
            return image
        except Exception as e:
            print(f"Error loading image: {e}")
            return None
        
    def preprocess(self, image, target_size=(224,224)):
        image=image.resize(target_size)
        image_array=np.array(image)/255.0
        return np.expand_dims(image_array, axis=0)
    
class ModelManager:
    def __init__(self):
        self.model=MobileNet(weights='imagenet')

    def load_model(self):
        return self.model
    
    def predict(self, model, preprocessed_image):
        predictions=model.predict(preprocessed_image)
        return predictions
    
class Classifier:
    def __init__(self, image_path):
        self.image_loader=ImageLoader(image_path)
        self.model_manager=ModelManager()

    def classify(self):
        image=self.image_loader.load_image()
        if image is None:
            return "Invalid image"
        
        preprocessed_image=self.image_loader.preprocess(image)
        model=self.model_manager.load_model()

        predictions=self.model_manager.predict(model,preprocessed_image)
        decoded_predictions=decode_predictions(predictions,top=3)
        return decoded_predictions
    
class FileHandler:
    @staticmethod
    def save_predictions(predictions, filename="predictions.txt"):
        with open(filename,"w") as file:
            for label,description,probability in predictions[0]:
                file.write(f"{description}: {probability:.2f}\n")
                
        # try:
        #     image=Image.open(image_path)
        # except FileNotFoundError:
        #     print("File not found")
        # except Exception as e:
        #     print(f"Error: {e}")


if __name__=="__main__":
    image_path="logo.png"
    classifier=Classifier(image_path)
    results=classifier.classify()

    if isinstance(results,str):
        print(results)
    else:
        for label,description,probability in results[0]:
            print(f"{description}: {probability:.2f}")

        # Save predictions to a file
        FileHandler.save_predictions(results)
        print("\nPredictions saved to predictions.txt")