import streamlit as st

# Page functions
def task_manager():
    st.title("Task Manager")
    task = st.text_input("Enter a new task")
    if st.button("Add Task"):
        if 'tasks' not in st.session_state:
            st.session_state['tasks'] = []
        if task:
            st.session_state['tasks'].append(task)
            st.success(f"Task '{task}' added!")
        else:
            st.error("Please enter a task")

    st.subheader("Task List")
    if 'tasks' in st.session_state and st.session_state['tasks']:
        for i, task in enumerate(st.session_state['tasks'], 1):
            st.write(f"{i}. {task}")
    else:
        st.write("No tasks added yet.")

def project_overview():
    st.title("Project Overview")
    st.write("Here, you can view and manage all projects.")
    project_name = st.text_input("Enter a new project name")
    if st.button("Add Project"):
        if 'projects' not in st.session_state:
            st.session_state['projects'] = []
        if project_name:
            st.session_state['projects'].append(project_name)
            st.success(f"Project '{project_name}' added!")
        else:
            st.error("Please enter a project name")

    st.subheader("Project List")
    if 'projects' in st.session_state and st.session_state['projects']:
        for i, project in enumerate(st.session_state['projects'], 1):
            st.write(f"{i}. {project}")
    else:
        st.write("No projects added yet.")

# Sidebar navigation
st.sidebar.title("Navigation")
page = st.sidebar.radio("Go to", ("Task Manager", "Project Overview"))

# Page routing
if page == "Task Manager":
    task_manager()
elif page == "Project Overview":
    project_overview()
