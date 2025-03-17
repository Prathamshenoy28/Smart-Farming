import streamlit as st
import joblib
import numpy as np

# Load the trained model
model_path = "crop_recommendation_model.pkl"
loaded_model = joblib.load(model_path)

# Define crop labels
crop_labels = {0: "Barley", 1: "Cotton", 2: "Maize", 3: "Rice", 4: "Sugarcane", 5: "Wheat"}

# Streamlit UI
st.title("Crop Recommendation System")
st.write("Enter the environmental conditions to get the best crop recommendation.")

# Input fields
soil_moisture = st.slider("Soil Moisture (%)", 40, 100, 60)
temperature = st.slider("Temperature (°C)", 10, 40, 28)
humidity = st.slider("Humidity (%)", 20, 100, 70)
light_intensity = st.slider("Light Intensity (Lux)", 10, 150, 50)

# Predict function
def predict_crop(soil_moisture, temperature, humidity, light_intensity):
    input_data = np.array([[soil_moisture, temperature, humidity, light_intensity]])
    predicted_label = loaded_model.predict(input_data)[0]
    return crop_labels.get(predicted_label, "Unknown Crop")

# Prediction button
if st.button("Predict Crop"):
    result = predict_crop(soil_moisture, temperature, humidity, light_intensity)
    st.success(f"Recommended Crop: {result}")
