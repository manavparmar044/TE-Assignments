from sentence_transformers import SentenceTransformer, util #type: ignore
import torch #type: ignore

faq_pairs = {
    "What is your name?": "I'm a customer support assistant.",
    "Do you offer refunds?": "Yes, we offer refunds within 30 days of purchase.",
    "Tell me about the product.": "Can you specify which product you're interested in?",
    "What is the price of the product?": "Please mention the product name for pricing details.",
    "Hello": "Hi there! How can I assist you today?",
    "Thank you": "You're welcome!",
    "Bye": "Goodbye! Have a great day.",
}


# Load pre-trained model
model = SentenceTransformer('paraphrase-MiniLM-L6-v2')

# Prepare data
questions = list(faq_pairs.keys())
question_embeddings = model.encode(questions, convert_to_tensor=True)

def get_response(user_input):
    user_embedding = model.encode(user_input, convert_to_tensor=True)
    cosine_scores = util.pytorch_cos_sim(user_embedding, question_embeddings)
    top_result = torch.argmax(cosine_scores)

    if cosine_scores[0][top_result] > 0.6:
        return faq_pairs[questions[top_result]]
    else:
        return "I'm sorry, I didn't understand that. Could you please rephrase?"


import streamlit as st #type: ignore

st.title("🧠 NLP Chatbot (BERT-powered)")
st.write("Ask a question about our services!")

user_input = st.text_input("You:", "")

if user_input:
    response = get_response(user_input)
    st.text_area("Bot:", response, height=100)