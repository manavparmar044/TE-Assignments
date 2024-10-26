import streamlit as st
st.title("Project Management dashboard")
st.header("Task manager")

task  = st.text_input("Enter a new task")

if st.button("Undo"):
    st.info("Last action undone")

task_length = len(task)

if(task_length>50):
    st.warning("Task description long")

st.write(f"Current length: {task_length}")

st.sidebar.header("Project Selector")
project = st.sidebar.selectbox("Select a project", ["Major Project","Research Project","Mini Project"])

st.write(f"Tasks:{project}")

if st.button("Submit"):
    if not task:
        st.error("Task cannot be empty")
    else:
        st.success(f"Task {task} submitted to {project}")