from django.conf.urls import url

from maze_generation import views

urlpatterns = [
    url(r'^maze_generation/', views.maze_generation_page)
]
