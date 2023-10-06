
def page_rank(graph, damping_factor=0.85, max_iterations=100, tolerance=1e-6):

    # :param graph: dict, key는 페이지, value는 해당 페이지로부터 나가는 링크의 리스트
    # :param damping_factor: float, 일반적으로 0.85로 설정
    # :param max_iterations: int, 최대 반복 횟수
    # :param tolerance: float, 수렴 조건
    # :return: dict, 각 페이지의 Page Rank 값

    num_pages = len(graph)
    pr = {page: 1/num_pages for page in graph}  # 초기화
    base_pr = (1 - damping_factor) / num_pages

    for i in range(max_iterations):
        next_pr = {page: base_pr for page in graph}
        for page, outgoing_links in graph.items():
            share_pr = pr[page] / len(outgoing_links)
            for link in outgoing_links:
                next_pr[link] += share_pr * damping_factor

        # 수렴 체크
        diff = sum(abs(next_pr[page] - pr[page]) for page in pr)
        if diff < tolerance:
            break

        pr = next_pr

    return pr

# 예제 그래프
graph = {
    'A': ['B', 'C'],
    'B': ['C'],
    'C': ['A'],
    'D': ['C']
}

print(page_rank(graph))