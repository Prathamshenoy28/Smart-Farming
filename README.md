## 🌱 Soil-Based Crop Recommendation System

This project uses environmental and soil data to intelligently recommend the most suitable crop to cultivate. By leveraging a machine learning model trained on key features like **soil moisture**, **temperature**, **humidity**, and **light intensity**, the system predicts the optimal crop from a set of common agricultural crops.

### 🔍 Features
- ✅ Accepts real-time or static soil and environmental input data
- ✅ Predicts crops including: **Barley, Cotton, Maize, Rice, Sugarcane**, and **Wheat**
- ✅ Simple integration with other agricultural automation systems
- ✅ Lightweight and efficient – uses a pre-trained model for instant predictions

### 🧠 How it Works
1. Input data: `[Soil Moisture, Temperature, Humidity, Light Intensity]`
2. The model (`crop_recommendation_model.pkl`) processes the input
3. Output: Recommended crop name

### 🛠️ Built With
- Python 🐍
- scikit-learn (for model training and prediction)
- pandas (for data handling)
- joblib (for model serialization)

