import streamlit as st

# Initialize a list in session_state to store tasks if it doesn't exist
if 'tasks' not in st.session_state:
    st.session_state['tasks'] = []

# Title and Header
st.title("Project Management Dashboard")
st.header("Task Manager")

# Task Input
task = st.text_input("Enter a new task")

# Button to Undo the last added task
if st.button("Undo"):
    if st.session_state['tasks']:
        st.session_state['tasks'].pop()
        st.info("Last task removed")
    else:
        st.warning("No tasks to undo")

# Task Length Check
task_length = len(task)
if task_length > 50:
    st.warning("Task description is too long (maximum 50 characters)")

# Display the Current Task Length
st.write(f"Current length: {task_length}")

# Sidebar Project Selector
st.sidebar.header("Project Selector")
project = st.sidebar.selectbox("Select a project", ["Major Project", "Research Project", "Mini Project"])

# Display the Selected Project and Task List
st.write(f"Tasks for: {project}")

# Submit Task Button
if st.button("Submit"):
    if not task:
        st.error("Task cannot be empty")
    else:
        # Add the task to the session_state task list
        st.session_state['tasks'].append((project, task))
        st.success(f"Task '{task}' submitted to {project}")
        st.text_input("Enter a new task", value="", key="reset")  # Reset input field

# Display Saved Tasks for the Selected Project
st.subheader("Task List")
for proj, saved_task in st.session_state['tasks']:
    if proj == project:
        st.write(f"- {saved_task}")
